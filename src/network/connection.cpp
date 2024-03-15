#include "connection.h"
#include <iostream>

Connection::Connection(DataType sendType,QObject *parent)
    : QTcpSocket(parent), writer(this)
{
    connect(this, &QTcpSocket::readyRead, this,
            &Connection::processReadyRead);

    switch(sendType)
    {
    case NewPeerConnection:
        connect(this, &QTcpSocket::connected,
                this, &Connection::sendNewPeer);
        break;
    }
}

Connection::Connection(qintptr socketDescriptor, QObject *parent)
    : Connection(Undefined,parent)
{
    setSocketDescriptor(socketDescriptor);
    reader.setDevice(this);
}

Connection::~Connection()
{
    if (isHandShakeMade)
        // Indicate clean shutdown.
        writer.endArray();
}

QString Connection::getName() const
{
    return otherUsername;
}

void Connection::setUsername(const QString &username)
{
    this->username = username;
}

void Connection::sendMessage(const QString &message)
{
    if (message.isEmpty())
        return;

    writer.startArray();
    writer.append(PlainText);
    writer.append(message);
    writer.endArray();
}

void Connection::sendData(std::list<MapElement*> els,Map* map, Game* g)
{
    int MaxBufferSize= 500000;
    int criticalBufferSize = MaxBufferSize*0.75;

    for(MapElement * el:els)
    {
        QByteArray byteArray;

        QDataStream stream(&byteArray, QIODevice::WriteOnly);
        stream << el->getName();
        stream << el->getOriginalPixMap();
        const int chunkSize = 8192;

        QByteArray compress = qCompress(byteArray);

        int i;
        for (i = 0; i < compress.size() - chunkSize; i += chunkSize) {

            QByteArray chunk = compress.mid(i, chunkSize);
            writer.startArray();
            writer.append(Image);
            writer.append(chunk);
            writer.endArray();
            qDebug() << "write " << chunk.size();
            flush();
            QThread::msleep(100);
        }

        if (compress.size() % chunkSize != 0) {
            qDebug() << "write " << compress.size() % chunkSize ;
            QByteArray lastChunk = compress.mid(i, compress.size() % chunkSize);
            qDebug() << lastChunk.size();
            writer.startArray();
            writer.append(Image);
            writer.append(lastChunk);
            writer.append(EndImage);
            writer.endArray();
            flush();
        }
    }

    writer.startArray();
    writer.append(MapType);
    writer.append(QString::fromStdString(map->serialize()));
    writer.endArray();
    flush();

    writer.startArray();
    writer.append(GameType);
    writer.append(QString::fromStdString(g->serialize()));
    writer.endArray();
    flush();
}

void Connection::sendNewPeer()
{
    writer.startArray(); // this array stay until the socket is delete
    writer.startArray();
    writer.append(NewPeerConnection);
    writer.append(username);
    writer.endArray();
    isHandShakeMade = true;

    if (!reader.device())
        reader.setDevice(this);

    emit waitingData();
}

void Connection::processReadyRead()
{
    QCborStreamReader::StringResult<QByteArray> r;
    // New data receive
    //QCborStreamReader::StringResult<qsizetype> result;
    reader.reparse();
    while (reader.lastError() == QCborError::NoError) {
        if (state == WaitingForConnection) {
            if (!reader.isArray())
                break;                  // protocol error

            reader.enterContainer();    // we'll be in this array forever
            state = ReadingConnection;
        }else if (reader.containerDepth() == 1) {
            // Verify the package receive and extract the DataType
            if (!reader.hasNext()) {
                reader.leaveContainer();
                disconnectFromHost();
                return;
            }

            if (!reader.isArray())
                break;                  // protocol error
            reader.enterContainer();
        }
        else if(reader.isArray())
        {
            reader.enterContainer();
        }else if (currentDataType == Undefined) {
            // We fetch the data type, to know what our package is for
            if (!reader.isInteger())
                break;                  // protocol error
            currentDataType = DataType(reader.toInteger());
            reader.next();
        } else {
            // We now read the command payload
            switch(currentDataType)
            {
            case NewPeerConnection:
                otherUsername = reader.readString().data;
                reader.readString();
                reader.leaveContainer();
                currentDataType = Undefined;
                processNewPeerConnection();
                break;
            case Image:
                qDebug() << "bytes available: " << bytesAvailable();
                r = reader.readByteArray();
                while (r.status == QCborStreamReader::Ok) {
                    byteBuffer += r.data;
                    r = reader.readByteArray();
                }

                if (r.status == QCborStreamReader::Error)
                    qDebug() << "error reading byte array";

                if(reader.hasNext() && DataType(reader.toInteger() == EndImage))
                {
                    qDebug() << "rend end image";
                    byteBuffer = qUncompress(byteBuffer);
                    processImage();
                    qDebug() << reader.lastError();
                    reader.next();
                    qDebug() << reader.lastError();
                }
                break;
            //TODO: Refactor
            case MapType:
                buffer = reader.readString().data;
                reader.readString();
                processMap();
                break;
            case GameType:
                buffer = reader.readString().data;
                reader.readString();
                processGame();
                break;
            default:
                buffer = reader.readString().data;
                reader.readString();
                processData();
                break;
            }

            if(currentDataType != Undefined)
            {
            qDebug() << reader.lastError();
            reader.leaveContainer();
            qDebug() << reader.lastError();
            currentDataType = Undefined;
            }
        }
    }
    qDebug() << reader.lastError();
}

void Connection::processNewPeerConnection()
{
    buffer.clear();

    if (!isValid()) {
        abort();
        return;
    }

    state = WaitingData;
    if(!isHandShakeMade)
        sendNewPeer();
}

void Connection::processImage()
{
    QString name;
    QPixmap map;
    QDataStream stream(&byteBuffer, QIODevice::ReadOnly);
    stream >> name;
    stream >> map;
    QString filepath = RESOURCE_DIRECTORY + name + "test";
    if (QFile::exists(filepath))
        QFile::remove(filepath);
    QFile file(filepath);
    file.open(QIODevice::WriteOnly);
    map.save(&file,"PNG");
    byteBuffer.clear();
}

void Connection::processData()
{
    switch (currentDataType) {
    case PlainText:
        qDebug() << "plainText";
        qDebug() << buffer;
        emit newMessage(otherUsername, buffer);
        break;
    default:
        break;
    }
    buffer.clear();
}

void Connection::processMap()
{
    Map m;
    m.deserialize(buffer.toStdString());
    m.save();
    buffer.clear();
}

void Connection::processGame()
{
    Game g;
    g.deserialize(buffer.toStdString());
    g.save();
    buffer.clear();
    state=ReadyForUse;
    emit readyForUse(g.getName());
}

#include "connection.h"
#include <QTimerEvent>
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

void Connection::sendImage(MapElement*el)
{
    QByteArray byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream << el->getName();
    stream << el->getOriginalPixMap();

    writer.startArray();
    writer.append(Image);
    writer.append(byteArray);
    writer.endArray();
}

void Connection::sendMap(Map *map)
{
    writer.startArray();
    writer.append(MapType);
    writer.append(QString::fromStdString(map->serialize()));
    writer.endArray();
}

void Connection::sendGame(Game *g)
{
    writer.startArray();
    writer.append(GameType);
    writer.append(QString::fromStdString(g->serialize()));
    writer.endArray();
}

void Connection::sendNewPeer()
{
    writer.startArray(); // this array stay until the socket in delete
    writer.startArray();
    writer.append(NewPeerConnection);
    writer.append(username);
    writer.endArray();
    isHandShakeMade = true;

    if (!reader.device())
        reader.setDevice(this);
}

void Connection::processReadyRead()
{
    QCborStreamReader::StringResult<QByteArray> r;
    // New data receive
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
                processNewPeerConnection();
                break;
            case Image:
                byteBuffer.clear();
                r = reader.readByteArray();
                byteBuffer += r.data;
                reader.readByteArray();
                processImage();
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
            reader.leaveContainer();
            currentDataType = Undefined;
        }
    }

    // It was to verify is we read overflow,
    // in our case we know exactly what we need to read, so why keep it?
    //if (reader.lastError() != QCborError::EndOfFile)
    //    abort();       // parse error

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

    emit waitingData();
}

void Connection::processImage()
{
    QString name;
    QPixmap map;
    QDataStream stream(&byteBuffer, QIODevice::ReadOnly);
    stream >> name;
    stream >> map;
    QString filepath = RESOURCE_DIRECTORY + name;
    if (QFile::exists(filepath))
        QFile::remove(filepath);
    QFile file(filepath);
    file.open(QIODevice::WriteOnly);
    map.save(&file,"PNG");
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



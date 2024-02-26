#include "connection.h"


#include "connection.h"

#include <QTimerEvent>
#include <iostream>

static const int TransferTimeout = 30 * 1000;

/*
 * Protocol is defined as follows, using the CBOR Data Definition Language:
 *
 *  protocol    = [
 *     greeting,        ; must start with a greeting command
 *     * command        ; zero or more regular commands after
 *  ]
 *  plaintext   = { 0 => text }
 *  map
 *  greeting    = { 3 => text }
 */


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
    if (isHandShakeMade) {
        // Indicate clean shutdown.
        writer.endArray();
        waitForBytesWritten(2000);
    }
}

QString Connection::getName() const
{
    return otherUsername;
}

void Connection::setUsername(const QString &username)
{
    this->username = username;
}

bool Connection::sendMessage(const QString &message)
{
    if (message.isEmpty())
        return false;

    writer.startArray();
    writer.append(PlainText);
    writer.append(message);
    writer.endArray();
    return true;
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

    state = ReadyForUse;

    if(!isHandShakeMade)
        sendNewPeer();

    emit readyForUse();
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

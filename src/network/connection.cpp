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

Connection::Connection(QObject *parent)
    : QTcpSocket(parent), writer(this)
{
    connect(this, &QTcpSocket::readyRead, this,
            &Connection::processReadyRead);
    connect(this, &QTcpSocket::connected,
            this, &Connection::sendGreetingMessage);
}

Connection::Connection(qintptr socketDescriptor, QObject *parent)
    : Connection(parent)
{
    setSocketDescriptor(socketDescriptor);
    reader.setDevice(this);
}

Connection::~Connection()
{
    if (isGreetingMessageSent) {
        // Indicate clean shutdown.
        writer.endArray();
        waitForBytesWritten(2000);
    }
}

QString Connection::name() const
{
    return username;
}

void Connection::setUsername(const QString &username)
{
    this->username = username;
}

bool Connection::sendMessage(const QString &message)
{
    if (message.isEmpty())
        return false;

    writer.startMap(1);
    writer.append(PlainText);
    writer.append(message);
    writer.endMap();
    return true;
}

void Connection::sendGreetingMessage()
{
    writer.startArray();        // this array never ends

    writer.startMap(1);
    writer.append(Greeting);
    writer.append(username);
    writer.endMap();
    isGreetingMessageSent = true;

    if (!reader.device())
        reader.setDevice(this);
}

void Connection::processReadyRead()
{
    // New data receive
    reader.reparse();
    while (reader.lastError() == QCborError::NoError) {
        if (state == WaitingForGreeting) {
            if (!reader.isArray())
                break;                  // protocol error

            reader.enterContainer();    // we'll be in this array forever
            state = ReadingGreeting;
        } else if (reader.containerDepth() == 1) {
            // Verify the package receive and extract the DataType
            if (!reader.hasNext()) {
                reader.leaveContainer();
                disconnectFromHost();
                return;
            }

            if (!reader.isMap() || !reader.isLengthKnown() || reader.length() != 1)
                break;                  // protocol error
            reader.enterContainer();
        } else if (currentDataType == Undefined) {
            // We fetch the data type, to know what our package is for
            if (!reader.isInteger())
                break;                  // protocol error
            currentDataType = DataType(reader.toInteger());
            reader.next();
        } else {
            // We now read the command payload

            //We can add later conditions for int, double...
            if (reader.isString()) {
                auto r = reader.readString();
                buffer += r.data;
                if (r.status != QCborStreamReader::EndOfString)
                    continue;
            } else if (reader.isNull()) {
                reader.next();
            } else {
                break;                   // protocol error
            }

            // Next state: no command read
            reader.leaveContainer();
            if (state == ReadingGreeting) {
                if (currentDataType != Greeting)
                    break;              // protocol error
                processGreeting();
            } else {
                processData();
            }
            currentDataType = Undefined;
        }
    }

    if (reader.lastError() != QCborError::EndOfFile)
        abort();       // parse error
}

void Connection::processGreeting()
{
    username = buffer;
    buffer.clear();

    if (!isValid()) {
        abort();
        return;
    }

    if (!isGreetingMessageSent)
        sendGreetingMessage();

    state = ReadyForUse;
    emit readyForUse();
}

void Connection::processData()
{
    switch (currentDataType) {
    case PlainText:
        qDebug() << "plainText";
        qDebug() << buffer;
        emit newMessage(username, buffer);
        break;
    default:
        break;
    }
    buffer.clear();
}

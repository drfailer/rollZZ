#include "User.h"
#include "connection.h"
#include "peermanager.h"

#include <QHostInfo>

#include <algorithm>
#include <functional>

User::User()
    : SERIALIZER(uuid, name),
      name(""),
      peerManager(new PeerManager(this))
{
    uuid = QUuid::createUuid().toString();
    server = new Server(this);

    peerManager->setServerPort(server->serverPort());
    connect(peerManager, &PeerManager::newConnection,
            this, &User::newConnection);
    connect(server, &Server::newConnection,
            this, &User::newConnection);
}

void User::sendMessage(const QString &message)
{
    if (message.isEmpty())
        return;

    qDebug() << peers.size();
    for (Connection *connection : peers.values())
    {
        qDebug() << connection;
        connection->sendMessage(message);
    }
}

void User::load()
{
    deserializeFile((UserFilePath).toStdString());
    // just to reload the name, can create a funtion setName later
    peerManager = new PeerManager(this);
    connect(peerManager, &PeerManager::newConnection,
            this, &User::newConnection);
}

void User::save()
{
    serializeFile((UserFilePath).toStdString());
}

QString User::getName() const
{
    return name;
}

QString User::getUuid() const
{
    return uuid;
}

int User::getPort() const
{
    return server->serverPort();
}

QString User::getIp() const
{
    return server->serverAddress().toString();
}


bool User::hasConnection(const QHostAddress &senderIp, int senderPort) const
{
    auto [begin, end] = peers.equal_range(senderIp);
    if (begin == peers.constEnd())
        return false;

    if (senderPort == -1)
        return true;

    for (; begin != end; ++begin) {
        Connection *connection = *begin;
        if (connection->peerPort() == senderPort)
            return true;
    }

    return false;
}

void User::initiateNewConnection(const QHostAddress &addressDest,const int portDest)
{
    peerManager->initiateNewConnection(addressDest,portDest);
}

void User::newConnection(Connection *connection)
{
    connection->setUsername(name);
    connect(connection, &Connection::errorOccurred, this, &User::connectionError);
    connect(connection, &Connection::disconnected, this, &User::disconnected);
    connect(connection, &Connection::readyForUse, this, &User::readyForUse);
}

void User::readyForUse()
{
    Connection *connection = qobject_cast<Connection *>(sender());
    if (!connection || hasConnection(connection->peerAddress(), connection->peerPort()))
        return;

    connect(connection,  &Connection::newMessage,
            this, &User::receiveNewMessage);

    peers.insert(connection->peerAddress(), connection);
    QString nick = connection->getName();
    if (!nick.isEmpty())
        emit newParticipant(nick);
}

void User::disconnected()
{
    if (Connection *connection = qobject_cast<Connection *>(sender()))
    {
        qDebug() << connection->error();
        qDebug() << connection->errorString();
        removeConnection(connection);
    }
}

void User::receiveNewMessage(const QString &from, const QString &message)
{
    emit newMessage(from,message);
}

void User::connectionError(QAbstractSocket::SocketError /* socketError */)
{
    if (Connection *connection = qobject_cast<Connection *>(sender()))
        removeConnection(connection);
}

void User::removeConnection(Connection *connection)
{
    if (peers.remove(connection->peerAddress(), connection) > 0) {
        QString nick = connection->getName();
        if (!nick.isEmpty())
            emit participantLeft(nick);
    }
    connection->deleteLater();
}

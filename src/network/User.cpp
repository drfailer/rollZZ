#include "User.h"
#include "connection.h"
#include "peermanager.h"

#include <QHostInfo>

#include <algorithm>
#include <functional>

User::User()
    : SERIALIZER(uuid, name),
      peerManager(new PeerManager(this))
{
    peerManager->setServerPort(server.serverPort());
    peerManager->startBroadcasting();
    connect(peerManager, &PeerManager::newConnection,
            this, &User::newConnection);
    connect(&server, &Server::newConnection,
            this, &User::newConnection);

    uuid = QUuid::createUuid().toString();
    name = "mannequin";
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
}

void User::save()
{
    serializeFile((UserFilePath).toStdString());
}

QString User::getName() const
{
    return name + '@' + QHostInfo::localHostName()
           + ':' + QString::number(server.serverPort());
}

QString User::getUuid() const
{
    return uuid;
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

void User::newConnection(Connection *connection)
{
    connection->setGreetingMessage(peerManager->userName());

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
            this, &User::newMessage);

    peers.insert(connection->peerAddress(), connection);
    QString nick = connection->name();
    if (!nick.isEmpty())
        emit newParticipant(nick);
}

void User::disconnected()
{
    if (Connection *connection = qobject_cast<Connection *>(sender()))
        removeConnection(connection);
}

void User::connectionError(QAbstractSocket::SocketError /* socketError */)
{
    if (Connection *connection = qobject_cast<Connection *>(sender()))
        removeConnection(connection);
}

void User::removeConnection(Connection *connection)
{
    if (peers.remove(connection->peerAddress(), connection) > 0) {
        QString nick = connection->name();
        if (!nick.isEmpty())
            emit participantLeft(nick);
    }
    connection->deleteLater();
}

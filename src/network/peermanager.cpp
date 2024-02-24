#include "User.h"
#include "connection.h"
#include "peermanager.h"

#include <QNetworkInterface>
#include <iostream>

PeerManager::PeerManager(User *client)
    : QObject(client), client(client)
{
    username = client->getName();
}

void PeerManager::setServerPort(int port)
{
    serverPort = port;
}

QString PeerManager::userName() const
{
    return username;
}

void PeerManager::initiateNewConnection(const QHostAddress &addressDest, const int portDest)
{
    Connection *connection = new Connection(this);
    emit newConnection(connection);
    connection->connectToHost(addressDest,portDest);
}



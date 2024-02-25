#include "User.h"
#include "connection.h"
#include "peermanager.h"

#include <QNetworkInterface>
#include <iostream>

PeerManager::PeerManager(User *client)
    : QObject(client), client(client)
{}

void PeerManager::setServerPort(int port)
{
    serverPort = port;
}

void PeerManager::initiateNewConnection(const QHostAddress &addressDest, const int portDest)
{
    Connection *connection = new Connection(this);
    connection->setUsername(client->getName());
    emit newConnection(connection);
    connection->connectToHost(addressDest,portDest);
}



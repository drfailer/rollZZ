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
    Connection *connection = new Connection(Connection::DataType::NewPeerConnection,this);
    connection->setUsername(client->getName());
    connection->setServerPort(client->getPort());
    emit newConnection(connection);
    connection->connectToHost(addressDest,portDest);
}



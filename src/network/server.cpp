#include "server.h"

Server::Server(QObject* parent): QTcpServer(parent)
{
    QList<QNetworkAddressEntry> adresses = QNetworkInterface::interfaceFromName("enp3s0").addressEntries();
    /* QHostAddress adress = adresses.first().ip(); */
    QHostAddress adress_public = QHostAddress("0.0.0.0");
    // Connect to the first ip of the interface (in my case 192.168.1.25)
    qDebug() << adress_public;
    listen(adress_public,7711);
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    Connection *connection = new Connection(socketDescriptor,this);
    emit newConnection(connection);
}

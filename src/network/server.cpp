#include "server.h"

Server::Server(QObject* parent): QTcpServer(parent)
{
    QList<QNetworkAddressEntry> adresses = QNetworkInterface::interfaceFromName("eno1").addressEntries();
    QHostAddress adress = adresses.first().ip();
    // Connect to the first ip of the interface (in my case 192.168.1.25)
    qDebug() << adress;
    // listen(adress,7711);
    listen(adress);
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    Connection *connection = new Connection(socketDescriptor,this);
    emit newConnection(connection);
}

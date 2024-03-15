#include "server.h"

Server::Server(QObject* parent): QTcpServer(parent)
{
    QHostAddress adress_public = QHostAddress("0.0.0.0");
    qDebug() << adress_public;
    listen(adress_public,7711);
    //listen(adress_public);
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    Connection *connection = new Connection(socketDescriptor,this);
    emit newConnection(connection);
}

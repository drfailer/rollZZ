#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include "connection.h"

class Server : public QTcpServer
{
    Q_OBJECT
  public:
    Server(QObject * parent = nullptr);

    signals:
    void newConnection(Connection * connection);
    protected:
    void incomingConnection(qintptr socketDescriptor) override;
};

#endif // SERVER_H

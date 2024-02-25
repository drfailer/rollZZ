#ifndef PEERMANAGER_H
#define PEERMANAGER_H

#include <QByteArray>
#include <QList>
#include <QObject>
#include <QTimer>
#include <QUdpSocket>

class User;
class Connection;

class PeerManager : public QObject
{
    Q_OBJECT

  public:
    PeerManager(User *client);

    void setServerPort(int port);
    // TODO later
    void setHostAddress(QHostAddress adr) {}
    QString userName() const;
    void initiateNewConnection(const QHostAddress &addressDest,const int portDest);

  signals:
    void newConnection(Connection *connection);

  private:
    User *client = nullptr;
    int serverPort = 0;
    QHostAddress hostAddress;
};


#endif // PEERMANAGER_H

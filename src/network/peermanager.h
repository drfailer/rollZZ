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
    //PeerManager(QObject * parent = nullptr): QObject(parent){}

    void setServerPort(int port);
    QString userName() const;
    void startBroadcasting();
    bool isLocalHostAddress(const QHostAddress &address) const;

  signals:
    void newConnection(Connection *connection);

  private slots:
    void sendBroadcastDatagram();
    void readBroadcastDatagram();

  private:
    void updateAddresses();

    User *client = nullptr;
    QList<QHostAddress> broadcastAddresses;
    QList<QHostAddress> ipAddresses;
    QUdpSocket broadcastSocket;
    QTimer broadcastTimer;
    QString username;
    int serverPort = 0;
};


#endif // PEERMANAGER_H

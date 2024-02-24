#ifndef USER_H
#define USER_H

#include "server.h"
#include "connection.h"

#include <QAbstractSocket>
#include <QHash>
#include <QHostAddress>
#include <QMultiHash>
#include <QUuid>
#include <QDir>
#include "serializer.hpp"
#include "qtconvertor.h"

#define UserFilePath QDir::homePath() + QString("/.local/user")

class PeerManager;

class User : public QObject
{
    Q_OBJECT
    SERIALIZABLE_WITH_CONVERTOR(QtConvertor,QString,QString)
  public:
    User();

    void sendMessage(const QString &message);
    QString getName() const;
    QString getUuid() const;
    bool hasConnection(const QHostAddress &senderIp, int senderPort = -1) const;
    void load();
    void save();

  signals:
    void newMessage(const QString &from, const QString &message);
    void newParticipant(const QString &nick);
    void participantLeft(const QString &nick);

  private slots:
    void newConnection(Connection *connection);
    void connectionError(QAbstractSocket::SocketError socketError);
    void disconnected();
    void readyForUse();

  private:
    void removeConnection(Connection *connection);

    QString uuid;
    QString name;
    PeerManager *peerManager;
    Server server;
    QMultiHash<QHostAddress, Connection *> peers;
};

#endif // USER_H

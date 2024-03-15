#ifndef CONNECTION_H
#define CONNECTION_H

#include <QCborStreamReader>
#include <QCborStreamWriter>
#include <QByteArray>
#include <QTcpSocket>
#include <mapelement.h>
#include "game.h"
#include <map.h>
#include <QDataStream>
#include <QFile>
#include <QThread>

static const int MaxBufferSize = 1024000;

class Connection : public QTcpSocket
{
    Q_OBJECT

  public:
    enum ConnectionState {
        WaitingForConnection,
        ReadingConnection,
        WaitingData,
        ReadyForUse
    };
    enum DataType {
        PlainText,
        Image,
        EndImage,
        MapType,
        GameType,
        NewPeerConnection,
        Undefined
    };

    explicit Connection(DataType sendType,QObject *parent = nullptr);
    explicit Connection(qintptr socketDescriptor, QObject *parent = nullptr);
    ~Connection();

    QString getName() const;
    void setUsername(const QString& username);
    void sendMessage(const QString &message);
    void sendData(std::list<MapElement*> els,Map* map, Game* g);

  signals:
    void readyForUse(QString gameName);
    void waitingData();
    void newMessage(const QString &from, const QString &message);
  private slots:
    void processReadyRead();
    void sendNewPeer();

  private:
    bool hasEnoughData();
    void processNewPeerConnection();
    void processData();
    void processImage();
    void processMap();
    void processGame();

    QCborStreamReader reader;
    QCborStreamWriter writer;
    QString username = "me";
    QString otherUsername = "other";
    QString buffer;
    QByteArray byteBuffer;  //= QByteArray(10000000,Qt::Initialization::Uninitialized);
    ConnectionState state = WaitingForConnection;
    DataType currentDataType = Undefined;
    bool isHandShakeMade = false;
};
#endif // CONNECTION_H

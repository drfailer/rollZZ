#ifndef CONNECTION_H
#define CONNECTION_H

#include <QCborStreamReader>
#include <QCborStreamWriter>
#include <QTimer>
#include <QElapsedTimer>
#include <QTcpSocket>

static const int MaxBufferSize = 1024000;

class Connection : public QTcpSocket
{
    Q_OBJECT

  public:
    enum ConnectionState {
        WaitingForConnection,
        ReadingConnection,
        ReadyForUse
    };
    enum DataType {
        PlainText,
        Map,
        NewPeerConnection,
        Undefined
    };

    explicit Connection(DataType sendType,QObject *parent = nullptr);
    explicit Connection(qintptr socketDescriptor, QObject *parent = nullptr);
    ~Connection();

    QString getName() const;
    void setUsername(const QString& username);
    bool sendMessage(const QString &message);

  signals:
    void readyForUse();
    void newMessage(const QString &from, const QString &message);
  private slots:
    void processReadyRead();
    void sendNewPeer();

  private:
    bool hasEnoughData();
    void processNewPeerConnection();
    void processData();

    QCborStreamReader reader;
    QCborStreamWriter writer;
    QString username = "me";
    QString otherUsername = "other";
    QString buffer;
    ConnectionState state = WaitingForConnection;
    DataType currentDataType = Undefined;
    bool isHandShakeMade = false;
};
#endif // CONNECTION_H

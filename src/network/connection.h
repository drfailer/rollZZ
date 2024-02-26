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
        ResponsePeerConnection,
        Undefined
    };

    explicit Connection(DataType sendType,QObject *parent = nullptr);
    explicit Connection(qintptr socketDescriptor, QObject *parent = nullptr);
    ~Connection();

    QString name() const;
    void setUsername(const QString& username);
    void setServerPort(const int serverPort);
    bool sendMessage(const QString &message);

  signals:
    void readyForUse();
    void newMessage(const QString &from, const QString &message);
    void newConnection(Connection*);
  private slots:
    void processReadyRead();
    void sendNewPeer();
    void sendPeerResponse();

  private:
    bool hasEnoughData();
    void processNewPeerConnection();
    void processResponsePeerConnection();
    void processData();

    QCborStreamReader reader;
    QCborStreamWriter writer;
    QString username = "src";
    int serverPort;
    QString buffer;
    ConnectionState state = WaitingForConnection;
    DataType currentDataType = Undefined;
    bool isNameSend = false;
    bool first_msg = false;
};
#endif // CONNECTION_H

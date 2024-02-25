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
        WaitingForGreeting,
        ReadingGreeting,
        ReadyForUse
    };
    enum DataType {
        PlainText,
        Map,
        Greeting,
        Undefined
    };

    explicit Connection(QObject *parent = nullptr);
    explicit Connection(qintptr socketDescriptor, QObject *parent = nullptr);
    ~Connection();

    QString name() const;
    void setUsername(const QString& username);
    bool sendMessage(const QString &message);

  signals:
    void readyForUse();
    void newMessage(const QString &from, const QString &message);
  private slots:
    void processReadyRead();
    void sendGreetingMessage();

  private:
    bool hasEnoughData();
    void processGreeting();
    void processData();

    QCborStreamReader reader;
    QCborStreamWriter writer;
    QString username = "src";
    QString buffer;
    ConnectionState state = WaitingForGreeting;
    DataType currentDataType = Undefined;
    bool isGreetingMessageSent = false;
};
#endif // CONNECTION_H

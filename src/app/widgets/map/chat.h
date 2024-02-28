#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include <QWidget>
#include <QTextTableFormat>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>

class Chat : public QWidget
{
    Q_OBJECT

  public:
    explicit Chat(QWidget *parent = nullptr);

  public slots:
    void addText(const QString &from, const QString &message);
    void returnPressed();

  private:
    QString myNickName;
    QVBoxLayout* layout;
    QTextTableFormat* tableFormat;
    QLineEdit* lineEdit;
    QTextEdit* textEdit;

};
#endif // CHAT_H

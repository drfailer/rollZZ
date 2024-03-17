#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include <QWidget>
#include <QTextTableFormat>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include <User.h>

class Chat : public QWidget
{
    Q_OBJECT

  public:
    explicit Chat(User* user,QWidget *parent = nullptr);

  public slots:
    void addText(const QString &from, const QString &message);
    void returnPressed();
    void userEnter(const QString &name);
    void userQuit(const QString &name);

  private:
    void notification(const QString& msg);

    User* user;
    QVBoxLayout* layout;
    QTextTableFormat* tableFormat;
    QLineEdit* lineEdit;
    QTextEdit* textEdit;

};
#endif // CHAT_H

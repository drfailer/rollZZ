#include "chat.h"

#include "chat.h"
#include <QScrollBar>
#include <QLineEdit>
#include <QTextTable>
#include <QMessageBox>
#include <QPushButton>

Chat::Chat(User* user,QWidget *parent)
    : QWidget(parent),user(user),
      layout(new QVBoxLayout(this))
{
    layout->setAlignment(Qt::AlignTop);
    tableFormat = new QTextTableFormat();
    lineEdit =new QLineEdit(this);
    textEdit =new QTextEdit(this);
    lineEdit->setFocusPolicy(Qt::StrongFocus);
    textEdit->setFocusPolicy(Qt::NoFocus);
    textEdit->setReadOnly(true);

    layout->addWidget(textEdit);
    layout->addWidget(lineEdit);

    connect(lineEdit, &QLineEdit::returnPressed,
            this, &Chat::returnPressed);
    connect(user, &User::newMessage,
            this, &Chat::addText);
    connect(user, &User::newParticipant,
            this, &Chat::userEnter);
    connect(user, &User::participantLeft,
            this, &Chat::userQuit);

    tableFormat->setBorder(0);
}

void Chat::addText(const QString &from, const QString &message)
{
    if (from.isEmpty() || message.isEmpty())
        return;

    QTextCursor cursor(textEdit->textCursor());
    cursor.movePosition(QTextCursor::End);
    QTextTable *table = cursor.insertTable(1, 2, *tableFormat);
    table->cellAt(0, 0).firstCursorPosition().insertText('<' + from + "> ");
    table->cellAt(0, 1).firstCursorPosition().insertText(message);
    QScrollBar *bar = textEdit->verticalScrollBar();
    bar->setValue(bar->maximum());
}

void Chat::notification(const QString &msg)
{
    if (msg.isEmpty())
        return;

    QColor color = textEdit->textColor();
    textEdit->setTextColor(Qt::gray);
    textEdit->append(msg);
    textEdit->setTextColor(color);
}

void Chat::returnPressed()
{
    QString text = lineEdit->text();
    if (text.isEmpty())
        return;

    addText(user->getName(),text);
    user->sendMessage(text);
    lineEdit->clear();
}

void Chat::userEnter(const QString &user)
{
    notification(tr("* %1 a rejoint").arg(user));
}

void Chat::userQuit(const QString & user)
{
    notification(tr("* %1 a quitté la partie").arg(user));
}

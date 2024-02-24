#include "chat.h"

#include "chat.h"
#include <QScrollBar>
#include <QLineEdit>
#include <QTextTable>
#include <QMessageBox>
#include <QPushButton>

Chat::Chat(QWidget *parent)
    : QWidget(parent),
      layout(new QVBoxLayout(this))
{
    layout->setAlignment(Qt::AlignTop);
    tableFormat = new QTextTableFormat();
    lineEdit =new QLineEdit("test",this);
    textEdit =new QTextEdit("coucou",this);
    lineEdit->setFocusPolicy(Qt::StrongFocus);
    textEdit->setFocusPolicy(Qt::NoFocus);
    textEdit->setReadOnly(true);

    layout->addWidget(textEdit);
    layout->addWidget(lineEdit);

    connect(lineEdit, &QLineEdit::returnPressed,
            this, &Chat::returnPressed);
    /**connect(&client, &Client::newMessage,
            this, &ChatDialog::appendMessage);
    connect(&client, &Client::newParticipant,
            this, &ChatDialog::newParticipant);
    connect(&client, &Client::participantLeft,
            this, &ChatDialog::participantLeft);**/

    myNickName = "test";
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

void Chat::returnPressed()
{
    QString text = lineEdit->text();
    if (text.isEmpty())
        return;

    addText(myNickName,text);
    //client.sendMessage(text);
    lineEdit->clear();
}

/**void ChatDialog::newParticipant(const QString &nick)
{
    if (nick.isEmpty())
        return;

    QColor color = textEdit->textColor();
    textEdit->setTextColor(Qt::gray);
    textEdit->append(tr("* %1 has joined").arg(nick));
    textEdit->setTextColor(color);
    listWidget->addItem(nick);
}

void ChatDialog::participantLeft(const QString &nick)
{
    if (nick.isEmpty())
        return;

    QList<QListWidgetItem *> items = listWidget->findItems(nick,
                                                           Qt::MatchExactly);
    if (items.isEmpty())
        return;

    delete items.at(0);
    QColor color = textEdit->textColor();
    textEdit->setTextColor(Qt::gray);
    textEdit->append(tr("* %1 has left").arg(nick));
    textEdit->setTextColor(color);
}

void ChatDialog::showInformation()
{
    if (listWidget->count() == 1) {
        QMessageBox::information(this, tr("Chat"),
                                 tr("Launch several instances of this "
                                    "program on your local network and "
                                    "start chatting!"));
    }
}**/

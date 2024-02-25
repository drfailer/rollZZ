#include "joingamepopup.h"
#include <QLineEdit>
#include "tools/popup.h"

JoinGamePopup::JoinGamePopup(): Popup("Game Info"),idEdit(new QLineEdit("192.168.1.25")),portEdit(new QLineEdit("7711"))
{
    QValidator *validator = new QIntValidator(0, 99999, this);
    QRegularExpression ipFormat("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    QRegularExpressionValidator* ipValidator = new QRegularExpressionValidator(ipFormat,this);

    portEdit->setValidator(validator);
    idEdit->setValidator(ipValidator);

    add("id:", idEdit);
    add("port:", portEdit);
}

QHostAddress JoinGamePopup::getIp() const
{
    return QHostAddress(idEdit->text());
}

int JoinGamePopup::getPort() const
{
    return portEdit->text().toInt();
}

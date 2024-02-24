#ifndef JOINGAMEPOPUP_H
#define JOINGAMEPOPUP_H


#include <QLineEdit>
#include "tools/popup.h"
#include <QHostAddress>
#include <QIntValidator>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

class JoinGamePopup : public Tools::Popup
{
    Q_OBJECT
  public:
    JoinGamePopup();
    QHostAddress getIp() const;
    int getPort() const;
  private:
    QLineEdit idEdit;
    QLineEdit portEdit;

};

#endif // JOINGAMEPOPUP_H

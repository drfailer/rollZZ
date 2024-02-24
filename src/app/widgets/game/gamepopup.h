#ifndef GAMEPOPUP_H
#define GAMEPOPUP_H

#include "tools/popup.h"
#include "QLineEdit"

class GamePopup : public Tools::Popup
{
    Q_OBJECT
  public:
    GamePopup(const QString name = "newgame");
    QString getName() const {return nameEdit.text();}
  private:
    QLineEdit nameEdit;
};

#endif // GAMEPOPUP_H

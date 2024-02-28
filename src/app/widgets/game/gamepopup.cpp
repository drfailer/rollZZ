#include "gamepopup.h"

GamePopup::GamePopup(const QString name):
Popup("New Game"),
nameEdit(name)
{
    add("Name:", &nameEdit);
}

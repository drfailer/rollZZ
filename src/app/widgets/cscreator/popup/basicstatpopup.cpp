#include "basicstatpopup.h"
#include <iostream>

namespace CSCreator {

BasicStatPopup::BasicStatPopup(const QString &title):
    CSCreatorPopup(title),
    nameEdit("stat name"),
    valueMaxEdit(this),
    diceEditWgt(this)
{
    // TODO: create a form
    valueMaxEdit.setValue(20);
    add(&nameEdit);
    add(&valueMaxEdit);
    add(&diceEditWgt);
}

BasicStatPopup::BasicStatPopup():
    BasicStatPopup("STATISTIC")
{
}

BasicStatPopup::BasicStatPopup(const QString &name, int maxValue, Dice dice):
    BasicStatPopup()
{
    valueMaxEdit.setValue(maxValue);
    nameEdit.setText(name);
    diceEditWgt.setFaces(dice.getFaces());
    diceEditWgt.setNumber(dice.getDiceNumber());
}

} // end namespace CSCreator

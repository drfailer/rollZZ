#include "basicstatpopup.h"

namespace CSCreator {

BasicStatPopup::BasicStatPopup(const QString &title):
    Popup(title),
    nameEdit("stat name")
{
    // TODO: create a form
    valueMaxEdit.setValue(20);
    add("Name:", &nameEdit);
    add("Value max:", &valueMaxEdit);
    add("Dice:", &diceEditWgt);
}

BasicStatPopup::BasicStatPopup():
    BasicStatPopup("STATISTIC")
{
}

BasicStatPopup::BasicStatPopup(const QString &name, int maxValue, Dice dice, const QString& title):
    BasicStatPopup(title)
{
    valueMaxEdit.setValue(maxValue);
    nameEdit.setText(name);
    diceEditWgt.setFaces(dice.getFaces());
    diceEditWgt.setNumber(dice.getDiceNumber());
}

} // end namespace CSCreator

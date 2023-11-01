#include "statcreationpopup.h"
#include <iostream>

StatCreationPopup::StatCreationPopup():
    CSCreatorPopup("STATISTIC"),
    nameEdit("stat name"),
    valueMaxEdit(0),
    diceEdit(this)
{
    // dices
    diceEdit.addItem("1d20", 0);
    diceEdit.addItem("1d10", 1);
    diceEdit.addItem("1d6", 3);
    diceEdit.addItem("1d4", 4);

    // add elements to the popup
    add(&nameEdit);
    add(&valueMaxEdit);
    add(&diceEdit);
}

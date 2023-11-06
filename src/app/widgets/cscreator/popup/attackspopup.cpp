#include "attackspopup.h"

AttacksPopup::AttacksPopup():
    CSCreatorPopup("ATTACKS & SPELLS"),
    nameEdit("name"),
    maxItemsEdit(this),
    dataBaseEdit(this)
{
    maxItemsEdit.setMinimum(0);
    maxItemsEdit.setValue(3);

    // database selector for weapons
    dataBaseEdit.addItem("choose a database...", 0);

    add(&nameEdit);
    add(&maxItemsEdit);
    add(&dataBaseEdit);
}

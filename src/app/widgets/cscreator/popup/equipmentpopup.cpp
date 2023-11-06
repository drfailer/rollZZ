#include "equipmentpopup.h"

EquipmentPopup::EquipmentPopup():
    CSCreatorPopup("EQUIPMENT"),
    nameEdit("name"),
    maxItemsEdit(this),
    dataBaseEdit(this)
{
    maxItemsEdit.setValue(3);
    maxItemsEdit.setMinimum(0);

    // database selector for weapons
    dataBaseEdit.addItem("choose a database...", 0);

    // TODO: we may wan't to configure the fields that are use (ex: we may want not to use weight).
    // TODO: add a list of weaponType / damageType => make a combobox in the sheet editor ?
    // NOTE: this ^ require to modify the CS tree.

    add(&nameEdit);
    add(&maxItemsEdit);
    add(&dataBaseEdit);
}

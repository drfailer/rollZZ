#include "attackspopup.h"

namespace CSCreator {

AttacksPopup::AttacksPopup(const QString name, int maxItems):
    Popup("ATTACKS & SPELLS"),
    nameEdit(name),
    maxItemsEdit(this)
{
    maxItemsEdit.setMinimum(0);
    maxItemsEdit.setValue(maxItems);

    // database selector for weapons
    // dataBaseEdit.addItem("choose a database...", 0);

    add("Name:", &nameEdit);
    add("Max items:", &maxItemsEdit);
}

} // end namespace CScreator

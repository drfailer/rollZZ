#include "attackspopup.h"

namespace CSCreator {

AttacksPopup::AttacksPopup(const QString name, int maxItems):
    CSCreatorPopup("ATTACKS & SPELLS"),
    nameEdit(name),
    maxItemsEdit(this)
{
    maxItemsEdit.setMinimum(0);
    maxItemsEdit.setValue(maxItems);

    // database selector for weapons
    // dataBaseEdit.addItem("choose a database...", 0);

    add(&nameEdit);
    add(&maxItemsEdit);
}

} // end namespace CScreator

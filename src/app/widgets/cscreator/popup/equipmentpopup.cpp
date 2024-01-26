#include "equipmentpopup.h"

namespace CSCreator {

EquipmentPopup::EquipmentPopup(bool useWeight, int maxWeight, int maxItems):
    Popup("EQUIPMENT"),
    useWeightRBtn("use weight", this),
    maxWeightBox(this),
    maxItemsBox(this)
{
    maxWeightBox.setMinimum(0);
    maxItemsBox.setMinimum(0);

    useWeightRBtn.setChecked(useWeight);
    maxWeightBox.setValue(maxWeight);
    maxItemsBox.setValue(maxItems);

    // TODO: we may wan't to configure the fields that are use (ex: we may want not to use weight).
    // TODO: add a list of weaponType / damageType => make a combobox in the sheet editor ?
    // NOTE: this ^ require to modify the CS tree.

    add("Use weight:", &useWeightRBtn);
    add("Max weight:", &maxWeightBox);
    add("Max items:", &maxItemsBox);
}

} // end namespace CSCreator

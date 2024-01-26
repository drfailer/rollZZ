#include "equipment.h"
#include "component.h"

#include <equipmentpopup.h>

namespace CSCreator {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

Equipment::Equipment(CS::Equipment *equipment, QWidget *parent):
    Component("Equipment", parent),
    equipment(equipment)
{
    update(true, 100, 10);
    bodyAdd(&useWeightLabel);
    bodyAdd(&maxWeightLabel);
    bodyAdd(&maxItemsLabel);
    connectSettings();
}

/******************************************************************************/
/*                                  settings                                  */
/******************************************************************************/

genSettingsPopup(Equipment, equipmentPopup, EquipmentPopup, {
    update(equipmentPopup->getUseWeight(), equipmentPopup->getMaxWeight(), equipmentPopup->getMaxItems());
}, equipment->getUseWeight(), equipment->getMaxWeight(), equipment->getMaxItems());

void Equipment::update(bool useWeight, int maxWeight, int maxItems) {
    equipment->setUseWeight(useWeight);
    equipment->setMaxWeight(maxWeight);
    equipment->setMaxItems(maxItems);
    useWeightLabel.setText("use weight: " + QString(useWeight? "true":"false"));
    maxWeightLabel.setText("max weight: " + QString::number(maxWeight));
    maxItemsLabel.setText("max items: " + QString::number(maxItems));
}

} // end namespace CSCreator

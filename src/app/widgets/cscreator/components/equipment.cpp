#include "equipment.h"
#include "component.h"

#include <equipmentpopup.h>

namespace CSCreator {

Equipment::Equipment(bool useWeight, int maxWeight, int maxItems, QWidget *parent):
    Component("Equipment", parent),
    useWeightLabel("use weight: " + QString(useWeight? "true":"false"), this),
    maxWeightLabel("max weight: " + QString::number(maxWeight), this),
    maxItemsLabel("max items: " + QString::number(maxItems), this),
    useWeight(useWeight),
    maxWeight(maxWeight),
    maxItems(maxItems)
{
    bodyAdd(&useWeightLabel);
    bodyAdd(&maxWeightLabel);
    bodyAdd(&maxItemsLabel);
    connectSettings();
}

genSettingsPopup(Equipment, equipmentPopup, EquipmentPopup, {
    useWeight = equipmentPopup->getUseWeight();
    maxWeight = equipmentPopup->getMaxWeight();
    maxItems = equipmentPopup->getMaxItems();
    useWeightLabel.setText("use weight: " + QString(useWeight? "true":"false"));
    maxWeightLabel.setText("max weight: " + QString::number(maxWeight));
    maxItemsLabel.setText("max items: " + QString::number(maxItems));
}, useWeight, maxWeight, maxItems);

} // end namespace CSCreator

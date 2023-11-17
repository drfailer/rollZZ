#include "equipment.h"

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
    connectSettingFunction(this, [&]() { this->settingsPopup(); });
}

void Equipment::settingsPopup()
{
    if (equipmentPopup == nullptr) {
        equipmentPopup = new EquipmentPopup(useWeight, maxWeight, maxItems);
    }
    equipmentPopup->show();
    connect(equipmentPopup, &EquipmentPopup::confirm, this, [&](bool confirm) {
        if (confirm) {
            useWeight = equipmentPopup->getUseWeight();
            maxWeight = equipmentPopup->getMaxWeight();
            maxItems = equipmentPopup->getMaxItems();
            useWeightLabel.setText("use weight: " + QString(useWeight? "true":"false"));
            maxWeightLabel.setText("max weight: " + QString::number(maxWeight));
            maxItemsLabel.setText("max items: " + QString::number(maxItems));
        }
        delete equipmentPopup;
        equipmentPopup = nullptr;
    });
}

} // end namespace CSCreator

#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "component.h"

namespace CSCreator {

class EquipmentPopup;

class Equipment : public Component
{
public:
    Equipment(bool useWeight = true, int maxWeight = 0, int maxItems = 0, QWidget* parent = nullptr);
    void settingsPopup();

private:
    EquipmentPopup *equipmentPopup = nullptr;

private:
    QLabel useWeightLabel;
    QLabel maxWeightLabel;
    QLabel maxItemsLabel;
    bool useWeight;
    int maxWeight;
    int maxItems;
};

} // end namespace CSCreator

#endif // EQUIPMENT_H

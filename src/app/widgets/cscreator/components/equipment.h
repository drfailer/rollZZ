#ifndef CSCREATOR_EQUIPMENT_H
#define CSCREATOR_EQUIPMENT_H

#include "component.h"
#include "CS/equipment.h"

namespace CSCreator {

class EquipmentPopup;

class Equipment : public Component
{
public:
    Equipment(CS::Equipment *equipment, bool useWeight = true, int maxWeight = 0, int maxItems = 0, QWidget* parent = nullptr);
    void settingsPopup() override;

private:
    EquipmentPopup *equipmentPopup = nullptr;

private:
    QLabel useWeightLabel;
    QLabel maxWeightLabel;
    QLabel maxItemsLabel;

    CS::Equipment *equipment = nullptr;

    void update(bool useWeight, int maxWeight, int maxItems);
};

} // end namespace CSCreator

#endif // EQUIPMENT_H

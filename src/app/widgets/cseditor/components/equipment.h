#ifndef CSEDITOR_EQUIPMENT_H
#define CSEDITOR_EQUIPMENT_H

#include "component.h"
#include "CS/equipment.h"
#include <QPushButton>

namespace CSEditor {

class Equipment : public Component
{
public:
    Equipment(CS::Equipment *equipment, QWidget* parent = nullptr);

private:
    QPushButton addItemBtn;
    CS::Equipment *equipment = nullptr;
};

} // end namespace CSEditor

#endif // EQUIPMENT_H

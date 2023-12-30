#ifndef CSEDITOR_EQUIPMENT_H
#define CSEDITOR_EQUIPMENT_H

#include "component.h"
#include "CS/equipment.h"
#include "cseditor/components/item.h"
#include <QPushButton>
#include <QList>

namespace CSEditor {

class Item;

class Equipment : public Component
{
    Q_OBJECT
public:
    Equipment(CS::Equipment *equipment, QWidget* parent = nullptr);
    ~Equipment();
    void addItem();

private:
    CS::Equipment *equipment = nullptr;
    QPushButton addItemBtn;
    QList<Item*> items;

    /* helpter function *******************************************************/
    int totalWeight() const {
        int sum = 0;
        for (Item *item : items) {
            sum += item->getWeight();
        }
        return sum;
    }

    QString weightStr() const {
        int weight = totalWeight();
        return " (" + QString::number(weight) + "/" + QString::number(equipment->getMaxWeight()) + ")";
    }
};

} // end namespace CSEditor

#endif // EQUIPMENT_H

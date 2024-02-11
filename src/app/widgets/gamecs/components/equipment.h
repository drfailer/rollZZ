#ifndef GAMECS_EQUIPMENT_H
#define GAMECS_EQUIPMENT_H

#include "component.h"
#include "CS/equipment.h"
#include <QPushButton>
#include <QList>

namespace GameCS {

class Item;

class Equipment : public Component {
    Q_OBJECT
public:
    Equipment(CS::Equipment *equipment, QWidget* parent = nullptr);
    ~Equipment();
    void addItem();

private:
    CS::Equipment *equipment = nullptr;
    QPushButton addItemBtn;

    /* helpter function *******************************************************/
    QString weightStr() const {
        int weight = equipment->getWeight();
        return " (" + QString::number(weight) + "/" + QString::number(equipment->getMaxWeight()) + ")";
    }

    void loadItem(CS::Item *item);
    void insertAndConnectItem(CS::Item *item, Item* newItemWgt);
};

} // end namespace GameCS

#endif // EQUIPMENT_H

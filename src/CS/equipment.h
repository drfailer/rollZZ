#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "component.h"
#include "item.h"

#include <QList>

namespace CS {
class Equipment : public Component
{

public:
    using Component::Component;
    Equipment();

    /* accessors ***************************************************************/
    void addItem(Item item) { items.push_back(item); }
    void removeItem(int index) { items.remove(index); }

private:
    QList<Item> items;
};
}

#endif // EQUIPMENT_H

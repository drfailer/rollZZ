#ifndef CS_EQUIPMENT_H
#define CS_EQUIPMENT_H

#include "component.h"
#include "item.h"

#include <QList>

namespace CS {
class Equipment : public Component
{

public:
    using Component::Component;
    Equipment(bool useWeight = true, int maxWeight = 60, int maxItems = 100);

    /* accessors ***************************************************************/
    void addItem(Item item);
    void removeItem(int index);
    void setMaxItems(int maxItems) { this->maxItems = maxItems; }
    int getMaxItems() const { return maxItems; }
    void setMaxWeight(int maxWeight) { this->maxWeight = maxWeight; }
    int getMaxWeight() const { return maxWeight; }
    void setUseWeight(bool useWeight) { this->useWeight = useWeight; }
    bool getUseWeight() const { return useWeight; }

private:
    QList<Item> items;
    bool useWeight;
    int maxWeight;
    int maxItems;
};
}

#endif // EQUIPMENT_H

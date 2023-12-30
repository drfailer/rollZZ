#ifndef CS_EQUIPMENT_H
#define CS_EQUIPMENT_H

#include "component.h"
#include "item.h"

#include <QList>

namespace CS {

class Equipment : public Component {
  public:
    using Component::Component;
    Equipment(bool useWeight = true, int maxWeight = 60, int maxItems = 100);
    ~Equipment();

    /* accessors
     * ***************************************************************/
    void addItem(Item *item);
    void removeItem(int index);
    void removeItem(Item *item);
    void setMaxItems(int maxItems) { this->maxItems = maxItems; }
    int getMaxItems() const { return maxItems; }
    void setMaxWeight(int maxWeight) { this->maxWeight = maxWeight; }
    int getMaxWeight() const { return maxWeight; }
    void setUseWeight(bool useWeight) { this->useWeight = useWeight; }
    bool getUseWeight() const { return useWeight; }
    Item *at(int index) { return items[index]; }
    int count() const { return items.count(); }

  private:
    QList<Item *> items;
    bool useWeight;
    int maxWeight;
    int maxItems;
};

} // namespace CS

#endif // EQUIPMENT_H

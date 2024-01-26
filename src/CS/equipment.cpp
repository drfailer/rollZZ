#include "equipment.h"

namespace CS {

/******************************************************************************/
/*                                constructor                                 */
/******************************************************************************/

Equipment::Equipment(bool _useWeight, int _maxWeight, int _maxItems):
    SERIALIZER(items, useWeight, maxWeight, maxItems),
    useWeight(_useWeight), maxWeight(_maxWeight), maxItems(_maxItems) {}

Equipment::~Equipment() {
    for (Item *item : items) {
        delete item;
    }
}

/******************************************************************************/
/*                             add & remove items                             */
/******************************************************************************/

void Equipment::addItem(Item *item) {
    if (items.count() < maxItems) {
        items.push_back(item);
    }
}

void Equipment::removeItem(int index) {
    if (index < items.count()) {
        Item *item = items.at(index);
        items.remove(index);
        delete item;
    }
}

void Equipment::removeItem(Item *item) {
    items.removeOne(item);
    delete item;
}

/******************************************************************************/
/*                                 get weight                                 */
/******************************************************************************/

int Equipment::getWeight() const {
    int sum = 0;

    for (Item *item : items) {
        sum += item->getWeight();
    }
    return sum;
}
} // namespace CS

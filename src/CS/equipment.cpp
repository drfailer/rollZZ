#include "equipment.h"

namespace CS {

/******************************************************************************/
/*                                constructor                                 */
/******************************************************************************/

Equipment::Equipment(bool useWeight, int maxWeight, int maxItems)
    : useWeight(useWeight), maxWeight(maxWeight), maxItems(maxItems) {}

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
        items.remove(index);
    }
}

void Equipment::removeItem(Item *item) { items.removeOne(item); }

} // namespace CS

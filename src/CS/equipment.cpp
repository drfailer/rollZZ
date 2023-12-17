#include "equipment.h"

/******************************************************************************/
/*                                constructor                                 */
/******************************************************************************/

CS::Equipment::Equipment(bool useWeight, int maxWeight, int maxItems):
    useWeight(useWeight),
    maxWeight(maxWeight),
    maxItems(maxItems)
{

}

/******************************************************************************/
/*                             add & remove items                             */
/******************************************************************************/

void CS::Equipment::addItem(Item item) {
    if (items.count() < maxItems) {
        items.push_back(item);
    }
}

void CS::Equipment::removeItem(int index) {
    if (index < items.count()) {
        items.remove(index);
    }
}


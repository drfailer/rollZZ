#include "CS/item.h"

namespace CS {

Item::Item(QString name, QString description, int quantity, int weight):
    name(name),
    description(description),
    quantity(quantity),
    weight(weight)
{
}

} // namespace CS

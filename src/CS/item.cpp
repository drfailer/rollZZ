#include "CS/item.h"

namespace CS {

Item::Item(QString _name, QString _description, int _quantity, int _weight):
    SERIALIZER(name, description, quantity, weight),
    name(_name),
    description(_description),
    quantity(_quantity),
    weight(_weight)
{
}

} // namespace CS

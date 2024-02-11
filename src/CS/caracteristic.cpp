#include "caracteristic.h"

namespace CS {

Caracteristic::Caracteristic(const QString &_name, const QString &_statName,
                             Dice _dice, int _checked):
    SERIALIZER(name, linkedStatName, bonus, checked, dice),
    name(_name),
    linkedStatName(_statName),
    checked(_checked),
    dice(_dice)
{
}

} // end namespace CS

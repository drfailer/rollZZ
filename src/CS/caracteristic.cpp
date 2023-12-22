#include "caracteristic.h"

namespace CS {

Caracteristic::Caracteristic(const QString& name, const QString& statName, Dice dice, int checked):
    name(name),
    linkedStatName(statName),
    checked(checked),
    dice(dice)
{ }

} // end namespace CS

#include "caracteristic.h"

namespace CS {

Caracteristic::Caracteristic(const QString& name, int bonus, Dice dice, int checked):
    name(name),
    bonus(bonus),
    checked(checked),
    dice(dice)
{ }

} // end namespace CS

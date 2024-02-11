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

int Caracteristic::roll() const {
    int diceResult = dice.roll();

    // critical miss configurable ?
    if (diceResult == 1) {
        return 1;
    }
    return diceResult + bonus;
}

} // end namespace CS

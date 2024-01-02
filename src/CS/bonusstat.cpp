#include "bonusstat.h"

namespace CS {

BonusStat::BonusStat(const QString& title, int _bonusValue, int value, int valueMax, Dice dice):
    BasicStat(title, value, valueMax, dice),
    SERIALIZER(bonusValue),
    bonusValue(_bonusValue)
{ }

int BonusStat::roll() const
{
    int diceResult = BasicStat::roll();

    // critical miss configurable ?
    if (diceResult == 1) {
        return 1;
    }
    return diceResult + bonusValue;
}

} // end namespace CS

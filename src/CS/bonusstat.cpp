#include "bonusstat.h"

namespace CS {

BonusStat::BonusStat(const QString& title, int bonusValue, int value, int valueMax, Dice dice):
    BasicStat(title, value, valueMax, dice),
    bonusValue(bonusValue)
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

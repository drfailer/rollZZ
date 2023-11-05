#include "bonusstat.h"

namespace CS {

BonusStat::BonusStat(QString title, int statValue, int bonusValue, Dice dice):
    Component(title),
    statValue(statValue),
    bonusValue(bonusValue),
    dice(dice)
{ }

BonusStat::BonusStat(int statValue, int bonusValue, Dice dice):
    BonusStat("bonus stat", statValue, bonusValue, dice)
{ }

int BonusStat::roll() const
{
    int diceResult = dice.roll();

    // critical miss configurable ?
    if (diceResult == 1) {
        return 1;
    }
    return diceResult + bonusValue;
}

} // end namespace CS

#include "basicstat.h"

namespace CS {

BasicStat::BasicStat(const QString& title, int value, int valueMax, Dice dice):
    Component(title),
    value(value),
    valueMax(valueMax),
    dice(dice)
{ }

BasicStat::BasicStat(int value, int valueMax, Dice dice):
    BasicStat("stat", value, valueMax, dice)
{ }

} // end namespace CS

#include "basicstat.h"

namespace CS {

BasicStat::BasicStat(const QString& name, int value, int valueMax, Dice dice):
    Component(name),
    value(value),
    valueMax(valueMax),
    dice(dice)
{ }

BasicStat::BasicStat(int value, int valueMax, Dice dice):
    BasicStat("stat", value, valueMax, dice)
{ }

} // end namespace CS

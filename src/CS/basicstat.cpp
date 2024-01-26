#include "basicstat.h"

namespace CS {

BasicStat::BasicStat(const QString& _name, int _value, int _valueMax, Dice _dice):
    Component(_name),
    SERIALIZER(value, valueMax, dice),
    value(_value),
    valueMax(_valueMax),
    dice(_dice)
{ }

BasicStat::BasicStat(int value, int valueMax, Dice dice):
    BasicStat("stat", value, valueMax, dice)
{ }

} // end namespace CS

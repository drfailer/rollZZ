#ifndef CS_BASICSTAT_H
#define CS_BASICSTAT_H

#include "component.h"
#include "dice.h"

namespace CS {

class BasicStat : public Component
{
public:
    BasicStat(const QString& name = "name", int value = 8, int valueMax = 20, Dice dice = Dice(20));
    BasicStat(int value, int valueMax = 20, Dice dice = Dice(20));
    int roll() const { return dice.roll(); }

    /* accessors ***************************************************************/
    int getValue() const { return value; }
    void setValue(int newValue) { value = newValue; }
    int getValueMax() const { return valueMax; }
    void setValueMax(int newValueMax) { valueMax = newValueMax; }
    Dice getDice() const { return dice; }
    void setDice(Dice newDice) { dice = newDice; }

private:
    int value;
    int valueMax;
    Dice dice;
};

} // end namespace CS

#endif // BASICSTAT_H

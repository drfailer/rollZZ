#ifndef BONUSSTAT_H
#define BONUSSTAT_H

#include "component.h"
#include "dice.h"

namespace CS {

class BonusStat : public Component
{
public:
    BonusStat(QString title, int statValue, int bonusValue, Dice dice = Dice(20));
    BonusStat(int statValue, int bonusValue, Dice dice = Dice(20));
    int roll() const;

    /* accessors ***************************************************************/
    int getStatValue() const { return statValue; }
    void setStatValue(int newStatValue) { statValue = newStatValue; }
    int getBonusValue() const { return bonusValue; }
    void setBonusValue(int newBonusValue) { bonusValue = newBonusValue; }
    Dice getDice() const { return dice; }
    void setDice(const Dice &newDice) { dice = newDice; }

private:
    int statValue;
    int bonusValue;
    Dice dice;
};

} // end namespace CS

#endif // BONUSSTAT_H

#ifndef CS_CARACTERISTIC_H
#define CS_CARACTERISTIC_H

#include "dice.h"

#include <QString>

namespace CS {

class Caracteristic
{
public:
    Caracteristic(const QString& name, const QString& statName, Dice dice = Dice(), int checked = false);
    int roll() const;

    /* accessors ***************************************************************/
    QString getName() const { return name; }
    void setName(const QString &newName) { name = newName; }
    int getBonus() const { return bonus; }
    void setBonus(int newBonus) { bonus = newBonus; }
    int getChecked() const { return checked; }
    void setChecked(int newChecked) { checked = newChecked; }
    Dice getDice() const { return dice; }
    void setDice(const Dice &newDice) { dice = newDice; }

private:
    QString name;
    QString linkedStatName;
    int bonus;
    int checked;
    Dice dice;
};

} // end namespace CS

#endif // CARACTERISTIC_H

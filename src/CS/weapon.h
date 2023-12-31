#ifndef CS_WEAPON_H
#define CS_WEAPON_H

#include "dice.h"

#include <QString>

namespace CS {
class Weapon
{
public:
    /* constructors ************************************************************/
    Weapon(const QString&, const QString&, Dice, Dice, int = 0, int = 0, int = 0, int = 0);
    Weapon(Dice, Dice, int = 0, int = 0, int = 0, int = 0);

    /* roll ********************************************************************/
    int rollAttack() const;
    int rollDamage() const;

    /* accessors ***************************************************************/
    QString getWeaponType() const { return weaponType; }
    void setWeaponType(const QString &newWeaponType) { weaponType = newWeaponType; }
    QString getDamageType() const { return damageType; }
    void setDamageType(const QString &newDamageType) { damageType = newDamageType; }
    Dice getAttackDice() const { return attackDice; }
    void setAttackDice(const Dice &newAttackDice) { attackDice = newAttackDice; }
    Dice getDamageDice() const { return damageDice; }
    void setDamageDice(const Dice &newDamageDice) { damageDice = newDamageDice; }
    int getAttackBonus() const { return attackBonus; }
    void setAttackBonus(int newAttackBonus) { attackBonus = newAttackBonus; }
    int getDamageBonus() const { return damageBonus; }
    void setDamageBonus(int newDamageBonus) { damageBonus = newDamageBonus; }
    int getRange() const { return range; }
    void setRange(int newRange) { range = newRange; }
    int getWeight() const { return weight; }
    void setWeight(int newWeight) { weight = newWeight; }

private:
    QString weaponType;
    QString damageType;
    Dice attackDice;
    Dice damageDice;
    int attackBonus;
    int damageBonus;
    int range;
    int weight;
};
}

#endif // WEAPON_H

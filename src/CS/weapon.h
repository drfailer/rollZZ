#ifndef CS_WEAPON_H
#define CS_WEAPON_H

#include "dice.h"
#include "tools/qtconvertor.h"
#include "serializer.hpp"

#include <QString>

namespace CS {
class Weapon {
    SERIALIZABLE_WITH_CONVERTOR(QtConvertor, QString, QString, Dice, Dice, int, int, int, int);
  public:
    /* constructors ***********************************************************/
    Weapon(const QString &name = "name", const QString &damageType = "none",
           Dice attackDice = Dice(), Dice damageDice = Dice(6, 1), int = 0,
           int = 0, int = 0, int = 0);
    Weapon(Dice, Dice, int = 0, int = 0, int = 0, int = 0);

    /* roll *******************************************************************/
    int rollAttack() const;
    int rollDamage() const;

    /* accessors **************************************************************/
    QString getWeaponType() const { return weaponType; }
    void setWeaponType(const QString &newWeaponType) {
        weaponType = newWeaponType;
    }
    QString getDamageType() const { return damageType; }
    void setDamageType(const QString &newDamageType) {
        damageType = newDamageType;
    }
    Dice getAttackDice() const { return attackDice; }
    void setAttackDice(const Dice &newAttackDice) {
        attackDice = newAttackDice;
    }
    Dice getDamageDice() const { return damageDice; }
    void setDamageDice(const Dice &newDamageDice) {
        damageDice = newDamageDice;
    }
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
} // namespace CS

#endif // WEAPON_H

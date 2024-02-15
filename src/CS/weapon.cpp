#include "weapon.h"

namespace CS {

Weapon::Weapon(const QString& _weaponType, const QString& _damageType,
        Dice _attackDice, Dice _damageDice, int _attackBonus, int _damageBonus,
        int _range, int _weight):
    SERIALIZER(weaponType, damageType, attackDice, damageDice, attackBonus,
            damageBonus, range, weight),
    weaponType(_weaponType),
    damageType(_damageType),
    attackDice(_attackDice),
    damageDice(_damageDice),
    attackBonus(_attackBonus),
    damageBonus(_damageBonus),
    range(_range),
    weight(_weight)
{ }

Weapon::Weapon(Dice attackDice, Dice damageDice, int attackBonus, int damageBonus, int range, int weight):
    CS::Weapon::Weapon("none", "none", attackDice, damageDice, attackBonus, damageBonus, range, weight)
{ }

int Weapon::rollAttack() const {
    int result = attackDice.roll() + attackBonus;

    if (result > 0) {
        result += attackBonus;
    }
    return result;
}

int Weapon::rollDamage() const {
    return damageDice.roll() + damageBonus;
}

} // end namespace CS

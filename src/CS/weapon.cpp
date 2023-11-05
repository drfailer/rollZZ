#include "weapon.h"

namespace CS {

Weapon::Weapon(const QString& weaponType, const QString& damageType, Dice attackDice, Dice damageDice, int attackBonus, int damageBonus, int range, int weight):
    weaponType(weaponType),
    damageType(damageType),
    attackDice(attackDice),
    damageDice(damageDice),
    attackBonus(attackBonus),
    damageBonus(damageBonus),
    range(range),
    weight(weight)
{ }

Weapon::Weapon(Dice attackDice, Dice damageDice, int attackBonus, int damageBonus, int range, int weight):
    CS::Weapon::Weapon("none", "none", attackDice, damageDice, attackBonus, damageBonus, range, weight)
{ }

int Weapon::rollAttack() const
{
    return attackDice.roll() + attackBonus;
}

int Weapon::rollDamage() const
{
    return damageDice.roll() + damageBonus;
}

} // end namespace CS

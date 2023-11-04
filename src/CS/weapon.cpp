#include "weapon.h"

namespace CS {

Weapon::Weapon(const QString& weaponType, const QString& damageType, Dice attackDice, Dice damageDice, int range, int weight):
    weaponType(weaponType),
    damageType(damageType),
    attackDice(attackDice),
    damageDice(damageDice),
    range(range),
    weight(weight)
{ }

Weapon::Weapon(Dice attackDice, Dice damageDice, int range, int weight):
    CS::Weapon::Weapon("none", "none", attackDice, damageDice, range, weight)
{ }

} // end namespace CS

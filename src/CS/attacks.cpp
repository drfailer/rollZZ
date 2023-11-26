#include "attacks.h"

namespace CS {

Attacks::Attacks(int maxWeaponNb, const QString title):
    Component(title),
    maxWeaponNb(maxWeaponNb)
{

}

void Attacks::addWeapon(Weapon weapon)
{
    if (weapons.count() < maxWeaponNb) {
        weapons.push_back(weapon);
    } else {
        // exceptions ?
    }
}

}

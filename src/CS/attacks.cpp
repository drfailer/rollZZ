#include "attacks.h"

namespace CS {

Attacks::Attacks(int _maxWeaponNb, const QString title):
    Component(title),
    SERIALIZER(maxWeaponNb, weapons),
    maxWeaponNb(_maxWeaponNb)
{

}

void Attacks::addWeapon(Weapon* weapon)
{
    if (weapons.count() < maxWeaponNb) {
        weapons.push_back(weapon);
    } else {
        // exceptions ?
    }
}

}

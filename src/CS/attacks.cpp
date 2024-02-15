#include "attacks.h"
#include "weapon.h"

namespace CS {

/******************************************************************************/
/*                          constructor & destructor                          */
/******************************************************************************/

Attacks::Attacks(int _maxWeaponNb, const QString title):
    Component(title),
    SERIALIZER(maxWeaponNb, weapons),
    maxWeaponNb(_maxWeaponNb)
{
}

Attacks::~Attacks() {
    clearWeapons();
}

/******************************************************************************/
/*                                 add weapon                                 */
/******************************************************************************/

void Attacks::addWeapon(Weapon* weapon) {
    weapons.push_back(weapon);
}

void Attacks::clearWeapons() {
    for (Weapon* weapon : weapons) {
        delete weapon;
    }
    weapons.clear();
}

} // end namespace CS

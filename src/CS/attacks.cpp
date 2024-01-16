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
    for (Weapon* weapon : weapons) {
        delete weapon;
    }
}

/******************************************************************************/
/*                                 add weapon                                 */
/******************************************************************************/

void Attacks::addWeapon(Weapon* weapon)
{
    if (weapons.count() < maxWeaponNb) {
        weapons.push_back(weapon);
    } else {
        // exceptions ?
    }
}

} // end namespace CS

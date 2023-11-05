#include "attacks.h"

CS::Attacks::Attacks(int maxNbWeapons):
    maxNbWeapons(maxNbWeapons)
{

}

void CS::Attacks::addWeapon(Weapon weapon)
{
    if (weapons.count() < maxNbWeapons) {
        weapons.push_back(weapon);
    } else {
        // exceptions ?
    }
}

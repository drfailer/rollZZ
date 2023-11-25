#ifndef CS_ATTACKS_H
#define CS_ATTACKS_H

#include "component.h"
#include "weapon.h"

#include <QList>

namespace CS {

class Attacks : public Component
{
public:
    Attacks(int maxNbWeapons);

    /* accessors ***************************************************************/
    void addWeapon(Weapon weapon);
    Weapon& at(int index) { return weapons[index]; }

private:
    int maxNbWeapons;
    QList<Weapon> weapons;
};

} // end namespace CS

#endif // ATTACKS_H

#include "gamecs/components/attacks.h"

#include "gamecs/components/weapon.h"
#include "component.h"
#include <QPushButton>
#include "CS/weapon.h"

namespace GameCS {

/******************************************************************************/
/*                          constructor & destructor                          */
/******************************************************************************/

Attacks::Attacks(CS::Attacks *attacks, QWidget* parent):
    Component(attacks->getTitle(), parent),
    attacks(attacks)
{
    // add weapons
    for (CS::Weapon *weapon : attacks->getWeapons()) {
        addWeapon(weapon);
    }

    // set style
    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #202020; }"
                  );
}

void Attacks::addWeapon(CS::Weapon *weapon) {
    Weapon* newWeaponWgt = new Weapon(weapon, this);

    bodyAdd(newWeaponWgt);
}

// TODO: remove weapons

} // end namespace GameCS

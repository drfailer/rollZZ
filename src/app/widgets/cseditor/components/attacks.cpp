#include "cseditor/components/attacks.h"

#include "component.h"
#include <QPushButton>
#include "CS/weapon.h"

namespace CSEditor {

/******************************************************************************/
/*                          constructor & destructor                          */
/******************************************************************************/

Attacks::Attacks(CS::Attacks *attacks, QWidget* parent):
    Component(attacks->getTitle(), parent),
    attacks(attacks),
    addWeaponBtn(new QPushButton("add weapon"))
{
    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #202020; }"
                  );

    bodyAdd(addWeaponBtn);
    connect(addWeaponBtn, &QPushButton::clicked, this, &Attacks::addWeapon);
}

void Attacks::addWeapon() {
    if (weapons.count() < attacks->getMaxWeaponNb()) {
        // insert before the add weapon button
        CS::Weapon* newWeapon = new CS::Weapon();
        Weapon* newWeaponWgt = new Weapon(newWeapon);

        attacks->addWeapon(newWeapon);
        weapons.push_back(newWeaponWgt);
        bodyInsert(bodyCount() - 1, newWeaponWgt);
    }
}

// TODO: remove weapons

} // end namespace CSEditor

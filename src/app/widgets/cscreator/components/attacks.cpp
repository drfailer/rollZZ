#include "attacks.h"

#include "attackspopup.h"
#include "component.h"

namespace CSCreator {

/******************************************************************************/
/*                          constructor & destructor                          */
/******************************************************************************/

Attacks::Attacks(CS::Attacks *attacks, QWidget* parent):
    Component("Attack", parent),
    attacks(attacks)
{
    update("name", 3);
    bodyAdd(&nameLabel);
    bodyAdd(&maxItemsLabel);
    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #202020; }"
                  );
    connectSettings();
}

/******************************************************************************/
/*                                  settings                                  */
/******************************************************************************/

genSettingsPopup(Attacks, attacksPopup, AttacksPopup, {
    update(attacksPopup->getName(), attacksPopup->getMaxItems());
}, attacks->getTitle(), attacks->getMaxWeaponNb())

void Attacks::update(const QString& title, int maxWeaponNb) {
    attacks->setTitle(title);
    attacks->setMaxWeaponNb(maxWeaponNb);
    nameLabel.setText("name: " + title);
    maxItemsLabel.setText("max weapon number: " + QString::number(maxWeaponNb));

    // add the weapons to cstree
    attacks->clearWeapons();
    for (int i = 0; i < maxWeaponNb; ++i) {
        attacks->addWeapon(new CS::Weapon());
    }
}

} // end namespace CSCreator

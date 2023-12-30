#include "cseditor/components/weapon.h"

namespace CSEditor {

Weapon::Weapon(CS::Weapon* weapon):
    weapon(weapon),
    layout(this),
    nameEdit("name", this),
    damageTypeEdit("damage type", this),
    damageDiceEdit(true, this),
    attackBonusEdit(this)
{
    layout.addWidget(&nameEdit);
    layout.addWidget(&attackBonusEdit);
    layout.addWidget(&damageDiceEdit);
    layout.addWidget(&damageTypeEdit);
    // TODO: compute default values for bonnuses (this should be done by the CS::Weapon)
    // TODO: connects
}

} // end namespace CSCrator

#include "cseditor/components/weapon.h"

namespace CSEditor {

Weapon::Weapon(CS::Weapon *weapon, QWidget* parent):
    QWidget(parent),
    weapon(weapon),
    layout(this),
    nameEdit("name", this),
    damageTypeEdit("damage type", this),
    damageDiceEdit(weapon->getDamageDice(), weapon->getDamageBonus(), true, this),
    attackBonusEdit(this)
{
    nameEdit.setText(weapon->getWeaponType());
    attackBonusEdit.setValue(weapon->getAttackBonus());
    damageTypeEdit.setText(weapon->getDamageType());
    layout.addWidget(&nameEdit);
    layout.addWidget(&attackBonusEdit);
    layout.addWidget(&damageDiceEdit);
    layout.addWidget(&damageTypeEdit);
    // TODO: compute default values for bonnuses (this should be done by the CS::Weapon)

    // connects
    connect(&nameEdit, &QLineEdit::textChanged, this, [&](const QString& newText) {
                this->weapon->setWeaponType(newText);
            });
    connect(&attackBonusEdit, &QSpinBox::valueChanged, this, [&](int newValue) {
                this->weapon->setAttackBonus(newValue);
            });
    connect(&damageDiceEdit, &DiceEdit::diceChanged, this, [&](const Dice& newDice) {
                this->weapon->setDamageDice(newDice);
            });
    connect(&damageDiceEdit, &DiceEdit::bonusChanged, this, [&](int newValue) {
                this->weapon->setDamageBonus(newValue);
            });
    connect(&damageTypeEdit, &QLineEdit::textChanged, this, [&](const QString& newText) {
                this->weapon->setDamageType(newText);
            });
    layout.setContentsMargins(0, 0, 0, 0);
}

} // end namespace CSCrator

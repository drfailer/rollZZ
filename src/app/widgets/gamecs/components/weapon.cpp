#include <QLabel>
#include "gamecs/components/weapon.h"
#include <iostream>

namespace GameCS {

Weapon::Weapon(CS::Weapon *weapon, QWidget* parent):
    QWidget(parent),
    weapon(weapon),
    layout(this),
    rollAttackBtn("roll attack"),
    rollDamageBtn("roll damage")
{
    layout.addWidget(new QLabel(
                weapon->getDamageType()
                + " [+" + QString::number(weapon->getAttackBonus())
                + "] " + weapon->getDamageDice().toString()
                + "+" + QString::number(weapon->getDamageBonus())
                + " " + weapon->getDamageType(), this));
    layout.addWidget(&rollAttackBtn);
    layout.addWidget(&rollDamageBtn);

    // connects
    connect(&rollAttackBtn, &QPushButton::clicked, this, [&]() {
                /* emit rolled(this->weapon->rollAttack()); */
                std::cout << this->weapon->rollAttack() << std::endl;
            });
    connect(&rollDamageBtn, &QPushButton::clicked, this, [&]() {
                /* emit rolled(this->weapon->rollDamage()); */
                std::cout << this->weapon->rollDamage() << std::endl;
            });
    layout.setContentsMargins(0, 0, 0, 0);
}

} // end namespace CSCrator

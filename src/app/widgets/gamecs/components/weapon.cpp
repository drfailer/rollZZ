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
                + " +" + QString::number(weapon->getAttackBonus())
                + " " + weapon->getDamageDice().toString()
                + " " + weapon->getDamageType(), this));
    layout.addWidget(&rollAttackBtn);
    layout.addWidget(&rollDamageBtn);

    // connects
    connect(&rollAttackBtn, &QPushButton::clicked, this, [&]() {
                /* emit rolled(weapon->getAttackDice().roll()); */
                std::cout << weapon->getAttackDice().roll() << std::endl;
            });
    connect(&rollDamageBtn, &QPushButton::clicked, this, [&]() {
                /* emit rolled(weapon->getDamageDice().roll()); */
                std::cout << weapon->getDamageDice().roll() << std::endl;
            });
    layout.setContentsMargins(0, 0, 0, 0);
}

} // end namespace CSCrator

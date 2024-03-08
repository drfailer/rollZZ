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
                QString message = "attack with "
                                + this->weapon->getWeaponType()
                                + ": "
                                + QString::number(this->weapon->rollAttack());
                emit rolled(message);
                std::cout << message.toStdString() << std::endl;
            });
    connect(&rollDamageBtn, &QPushButton::clicked, this, [&]() {
                QString message = "make damage with "
                                + this->weapon->getWeaponType()
                                + ": "
                                + QString::number(this->weapon->rollDamage());
                emit rolled(message);
                std::cout << message.toStdString() << std::endl;
            });
    layout.setContentsMargins(0, 0, 0, 0);
}

} // end namespace CSCrator

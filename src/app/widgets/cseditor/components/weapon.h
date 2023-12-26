#ifndef CSEDITOR_WEAPON_HPP
#define CSEDITOR_WEAPON_HPP

#include "CS/weapon.h"
#include "diceedit.h"
#include <QWidget>
#include <QBoxLayout>
#include <QSpinBox>

namespace CSEditor {

class Weapon : public QWidget
{
    Q_OBJECT
public:
    Weapon(CS::Weapon* weapon);
    ~Weapon() = default;

private:
    CS::Weapon* weapon;
    QHBoxLayout layout;
    DiceEdit attackDiceEdit;
    DiceEdit damageDiceEdit;
    QSpinBox attackBonusEdit; // NOTE: this sould be computed automatically
};

} // end namespace CSCrator

#endif

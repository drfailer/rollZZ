#ifndef CSEDITOR_WEAPON_HPP
#define CSEDITOR_WEAPON_HPP

#include "CS/weapon.h"
#include "diceedit.h"
#include <QBoxLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QWidget>

namespace CSEditor {

class Weapon : public QWidget {
    Q_OBJECT
  public:
    Weapon(CS::Weapon *weapon);
    ~Weapon() = default;

  private:
    CS::Weapon *weapon;
    QHBoxLayout layout;
    QLineEdit nameEdit;
    QLineEdit damageTypeEdit;
    DiceEdit damageDiceEdit;
    QSpinBox attackBonusEdit; // NOTE: this sould be computed automatically
};

} // namespace CSEditor

#endif

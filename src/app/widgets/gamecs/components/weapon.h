#ifndef GAMECS_WEAPON_HPP
#define GAMECS_WEAPON_HPP

#include "CS/weapon.h"
#include <QBoxLayout>
#include <QWidget>
#include <QPushButton>

namespace GameCS {

class Weapon : public QWidget {
    Q_OBJECT
  public:
    Weapon(CS::Weapon *weapon, QWidget* parent);
    ~Weapon() = default;

signals:
    void rolled(int);

  private:
    CS::Weapon *weapon;
    QHBoxLayout layout;
    QPushButton rollAttackBtn;
    QPushButton rollDamageBtn;
};

} // namespace GameCS

#endif

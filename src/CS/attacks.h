#ifndef CS_ATTACKS_H
#define CS_ATTACKS_H

#include "component.h"
#include "weapon.h"

#include <QList>

namespace CS {

class Attacks : public Component {
    SERIALIZABLE_SUPER(Component, int, QList<Weapon*>)
  public:
    Attacks(int maxWeaponNb = 3, const QString title = "attacks & spells");
    ~Attacks();

    /* accessors **************************************************************/
    void addWeapon(Weapon *weapon);
    Weapon *at(int index) { return weapons[index]; }

    void setMaxWeaponNb(int maxWeaponNb) { this->maxWeaponNb = maxWeaponNb; }
    int getMaxWeaponNb() const { return maxWeaponNb; }

  private:
    int maxWeaponNb;
    QList<Weapon *> weapons;
};

} // end namespace CS

#endif // ATTACKS_H

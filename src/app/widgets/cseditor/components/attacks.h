#ifndef CSEDITOR_ATTACKS_H
#define CSEDITOR_ATTACKS_H

#include "CS/attacks.h"
#include "cseditor/components/weapon.h"
#include "component.h"
#include <QSpinBox>
#include <QList>

namespace CSEditor {

class Attacks : public Component
{
    Q_OBJECT
public:
    Attacks(CS::Attacks *attack, QWidget *parent = nullptr);

private:
    CS::Attacks *attacks;
    // TODO: create a list of weaponds
    // TODO: add a button to add weapons
    // TODO: create a widget for weapons (damage, ...)
    QList<Weapon*> weapons;
    QPushButton *addWeaponBtn;

    /* methods ****************************************************************/
    void addWeapon();
};

} // end namespace CSEditor

#endif // ATTACKS_H

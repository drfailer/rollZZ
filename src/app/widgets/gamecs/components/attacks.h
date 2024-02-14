#ifndef GAMECS_ATTACKS_H
#define GAMECS_ATTACKS_H

#include "CS/attacks.h"
#include "tools/component.h"
#include <QSpinBox>
#include <QList>

namespace GameCS {

class Attacks : public Tools::Component
{
    Q_OBJECT
public:
    Attacks(CS::Attacks *attack, QWidget *parent = nullptr);

private:
    CS::Attacks *attacks;

    /* methods ****************************************************************/
    void addWeapon(CS::Weapon *weapon);
};

} // end namespace GameCS

#endif // ATTACKS_H

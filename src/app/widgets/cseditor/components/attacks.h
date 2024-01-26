#ifndef CSEDITOR_ATTACKS_H
#define CSEDITOR_ATTACKS_H

#include "CS/attacks.h"
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

    /* methods ****************************************************************/
    void addWeapon(CS::Weapon *weapon);
};

} // end namespace CSEditor

#endif // ATTACKS_H

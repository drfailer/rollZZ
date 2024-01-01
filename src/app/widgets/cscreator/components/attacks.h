#ifndef CSCREATOR_ATTACKS_H
#define CSCREATOR_ATTACKS_H

#include "CS/attacks.h"
#include "component.h"

namespace CSCreator {

class AttacksPopup;

class Attacks : public Component
{
    Q_OBJECT
public:
    Attacks(CS::Attacks *attack, QWidget *parent = nullptr);
    void settingsPopup() override;
    void update(const QString& title, int maxWeaponNb);

private:
    QLabel nameLabel;
    QLabel maxItemsLabel;
    AttacksPopup *attacksPopup = nullptr;
    CS::Attacks *attacks = nullptr;
};

} // end namespace CSCreator

#endif // ATTACKS_H

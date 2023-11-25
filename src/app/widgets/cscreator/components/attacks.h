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
    Attacks(CS::Attacks *attack, const QString name = "name", int maxItems = 3, QWidget *parent = nullptr);
    void settingsPopup() override;

private:
    QString name;
    int maxItems;
    QLabel nameLabel;
    QLabel maxItemsLabel;

    AttacksPopup *attacksPopup = nullptr;

    CS::Attacks *attack;
};

} // end namespace CSCreator

#endif // ATTACKS_H

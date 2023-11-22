#include "attacks.h"

#include "popup/attackspopup.h"

namespace CSCreator {

Attacks::Attacks(const QString name, int maxItems, QWidget* parent):
    Component("Attack", parent),
    name(name),
    maxItems(maxItems),
    nameLabel("name: " + name),
    maxItemsLabel("max items: " + QString::number(maxItems))
{
    bodyAdd(&nameLabel);
    bodyAdd(&maxItemsLabel);
    connectSettingFunction(this, [&]() { settingsPopup(); });
}

void Attacks::settingsPopup()
{
    if (attacksPopup == nullptr) {
        attacksPopup = new AttacksPopup(name, maxItems);
    }
    attacksPopup->show();
    connect(attacksPopup, &AttacksPopup::confirm, this, [&](bool confirm) {
        if (confirm) {
            name = attacksPopup->getName();
            maxItems = attacksPopup->getMaxItems();
            nameLabel.setText("name: " + name);
            maxItemsLabel.setText("max items: " + QString::number(maxItems));
        }
        delete attacksPopup;
        attacksPopup = nullptr;
    });
}

} // end namespace CSCreator

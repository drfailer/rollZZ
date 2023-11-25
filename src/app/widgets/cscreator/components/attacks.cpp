#include "attacks.h"

#include "component.h"
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
    connectSettings();
}

genSettingsPopup(Attacks, attacksPopup, AttacksPopup, {
    name = attacksPopup->getName();
    maxItems = attacksPopup->getMaxItems();
    nameLabel.setText("name: " + name);
    maxItemsLabel.setText("max items: " + QString::number(maxItems));
}, name, maxItems)

} // end namespace CSCreator

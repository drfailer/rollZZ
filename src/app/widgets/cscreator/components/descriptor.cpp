#include "descriptor.h"
#include "descriptorpopup.h"

namespace CSCreator {

Descriptor::Descriptor(const QString &name, QWidget* parent):
    Component("Descriptor", parent),
    nameLabel("name: " + name),
    name(name)
{
    bodyAdd(&nameLabel);
    connectSettingFunction(this, [&]() { settingsPopup(); });
}

Descriptor::Descriptor():
    Component("Descriptor")
{

}

void Descriptor::settingsPopup()
{
    if (descriptorPopup == nullptr) {
        descriptorPopup = new DescriptorPopup(name);
    }
    descriptorPopup->show();
    connect(descriptorPopup, &DescriptorPopup::confirm, this, [&](bool confirm) {
        if (confirm) {
            name = descriptorPopup->getName();
            nameLabel.setText("name: " + name);
        }
        delete descriptorPopup;
        descriptorPopup = nullptr;
    });
}

} // end namespace CSCreator

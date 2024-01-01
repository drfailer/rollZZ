#include "descriptor.h"
#include "descriptorpopup.h"

namespace CSCreator {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

Descriptor::Descriptor(CS::Descriptor *descriptor, QWidget *parent)
    : Component("Descriptor", parent), descriptor(descriptor) {
    update("name", CS::DescriptorTypes::ONELINE);
    bodyAdd(&nameLabel);
    bodyAdd(&typeLabel);
    connectSettings();
    // style
    setStyleSheet("QLabel { font-size: 18px; }"
            "QPushButton { font-size: 14px; border: 1px solid #282828; "
            "border-radius: 5%; }"
            "QFrame { background-color: #202020; }");
}

/******************************************************************************/
/*                                  settings                                  */
/******************************************************************************/

genSettingsPopup(Descriptor, descriptorPopup, DescriptorPopup, {
    update(descriptorPopup->getName(), descriptorPopup->getType());
}, descriptor->getTitle(), descriptor->getType())

void Descriptor::update(const QString &name, CS::DescriptorTypes type) {
    descriptor->setTitle(name);
    descriptor->setType(type);
    nameLabel.setText("name: " + name);
    typeLabel.setText("type: " + typeToString(type));
}

QString Descriptor::typeToString(CS::DescriptorTypes type) const {
    switch (type) {
    case CS::DescriptorTypes::ONELINE:
        return "oneline";
    case CS::DescriptorTypes::LONG:
        return "long";
    }
    return "none";
}

} // end namespace CSCreator

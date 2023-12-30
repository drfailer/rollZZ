#include "descriptor.h"
#include "descriptorpopup.h"

namespace CSCreator {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

Descriptor::Descriptor(CS::Descriptor *descriptor, const QString &name, QWidget* parent):
    Component("Descriptor", parent),
    descriptor(descriptor)
{
    update(name);
    bodyAdd(&nameLabel);
    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #202020; }"
                  );
    connectSettings();
}

/******************************************************************************/
/*                                  settings                                  */
/******************************************************************************/

// TODO: descriptor types

genSettingsPopup(Descriptor, descriptorPopup, DescriptorPopup, {
    update(descriptorPopup->getName());
}, descriptor->getTitle())

void Descriptor::update(const QString& name) {
    descriptor->setTitle(name);
    nameLabel.setText("name: " + name);
}

} // end namespace CSCreator

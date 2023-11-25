#include "descriptor.h"
#include "descriptorpopup.h"

namespace CSCreator {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

Descriptor::Descriptor(CS::Descriptor *descriptor, const QString &name, QWidget* parent):
    Component("Descriptor", parent),
    nameLabel("name: " + name),
    name(name),
    descriptor(descriptor)
{
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

genSettingsPopup(Descriptor, descriptorPopup, DescriptorPopup, {
    name = descriptorPopup->getName();
    nameLabel.setText("name: " + name);
}, name)

} // end namespace CSCreator

#include "descriptorpopup.h"

namespace CSCreator {

DescriptorPopup::DescriptorPopup(const QString& name, CS::DescriptorTypes type):
    Popup("DESCRIPTOR"),
    nameEdit(name)
{
    typeEdit.addItem("oneline", CS::DescriptorTypes::ONELINE);
    typeEdit.addItem("long", CS::DescriptorTypes::LONG);
    typeEdit.setCurrentIndex(type);

    add(&nameEdit);
    add(&typeEdit);
}

} // end namespace CSCreator

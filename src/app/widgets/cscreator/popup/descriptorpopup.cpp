#include "descriptorpopup.h"

namespace CSCreator {

DescriptorPopup::DescriptorPopup(const QString& name, CS::DescriptorTypes type):
    Popup("DESCRIPTOR"),
    nameEdit(name)
{
    typeEdit.addItem("oneline", CS::DescriptorTypes::ONELINE);
    typeEdit.addItem("long", CS::DescriptorTypes::LONG);
    typeEdit.setCurrentIndex(type);

    add("Name:", &nameEdit);
    add("Type:", &typeEdit);
}

} // end namespace CSCreator

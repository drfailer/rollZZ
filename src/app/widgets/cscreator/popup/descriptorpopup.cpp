#include "descriptorpopup.h"

namespace CSCreator {

DescriptorPopup::DescriptorPopup(const QString& name):
    CSCreatorPopup("DESCRIPTOR"),
    nameEdit(name)
{
    add(&nameEdit);
}

} // end namespace CSCreator

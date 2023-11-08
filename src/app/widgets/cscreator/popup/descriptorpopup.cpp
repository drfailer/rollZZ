#include "descriptorpopup.h"

namespace CSCreator {

DescriptorPopup::DescriptorPopup():
    CSCreatorPopup("DESCRIPTOR"),
    nameEdit("name")
{
    add(&nameEdit);
}

} // end namespace CSCreator

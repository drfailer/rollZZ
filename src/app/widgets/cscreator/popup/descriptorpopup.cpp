#include "descriptorpopup.h"

DescriptorPopup::DescriptorPopup():
    CSCreatorPopup("DESCRIPTOR"),
    nameEdit("name")
{
    add(&nameEdit);
}

#include "descriptorcreationpopup.h"

DescriptorCreationPopup::DescriptorCreationPopup():
    CSCreatorPopup("DESCRIPTOR"),
    nameEdit("name")
{
    add(&nameEdit);
}

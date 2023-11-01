#include "equipmentcreationpopup.h"

EquipmentCreationPopup::EquipmentCreationPopup():
    CSCreatorPopup("EQUIPMENT"),
    nameEdit("name")
{
    add(&nameEdit);
}

#include "categorycreationpopup.h"

CategoryCreationPopup::CategoryCreationPopup():
    CSCreatorPopup("CATEGORY"),
    nameEdit("name")
{
    add(&nameEdit);
}

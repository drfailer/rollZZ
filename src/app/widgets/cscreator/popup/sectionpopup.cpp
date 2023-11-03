#include "sectionpopup.h"

SectionPopup::SectionPopup():
    CSCreatorPopup("CATEGORY"),
    nameEdit("name")
{
    add(&nameEdit);
}

#include "sectionpopup.h"

SectionPopup::SectionPopup(const QString &defaultValue):
    CSCreatorPopup("SECTION"),
    nameEdit(defaultValue)
{
    add(&nameEdit);
}

SectionPopup::SectionPopup():
    SectionPopup("name")
{
}

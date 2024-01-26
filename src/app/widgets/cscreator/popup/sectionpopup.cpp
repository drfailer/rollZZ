#include "sectionpopup.h"

namespace CSCreator {

SectionPopup::SectionPopup(const QString &defaultValue):
    Popup("SECTION"),
    nameEdit(defaultValue)
{
    add("Title:", &nameEdit);
}

SectionPopup::SectionPopup():
    SectionPopup("name")
{
}

} // end namespace CSCrator

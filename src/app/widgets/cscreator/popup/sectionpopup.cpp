#include "sectionpopup.h"

namespace CSCreator {

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

} // end namespace CSCrator

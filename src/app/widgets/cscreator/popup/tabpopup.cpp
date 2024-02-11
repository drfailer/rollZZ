#include "tabpopup.h"

namespace CSCreator {

TabPopup::TabPopup(const QString& name, const QString& defaultText):
    Popup(name),
    nameEdit(defaultText)
{
    add("Title:", &nameEdit);
}

TabPopup::TabPopup(const QString& name):
    TabPopup(name, "name")
{
}

} // end namespace CSCreator

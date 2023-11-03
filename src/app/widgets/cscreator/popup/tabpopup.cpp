#include "tabpopup.h"

TabPopup::TabPopup(const QString& name, const QString& defaultText):
    CSCreatorPopup(name),
    nameEdit(defaultText)
{
    add(&nameEdit);
}

TabPopup::TabPopup(const QString& name):
    TabPopup(name, "name")
{
}

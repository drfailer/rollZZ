#include "newtabpopup.h"

NewTabPopup::NewTabPopup():
    CSCreatorPopup("NEW TAB"),
    nameEdit("name")
{
    add(&nameEdit);
}

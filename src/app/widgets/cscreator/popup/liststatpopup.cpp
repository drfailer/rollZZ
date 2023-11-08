#include "liststatpopup.h"

namespace CSCreator {

ListStatPopup::ListStatPopup():
    CSCreatorPopup("LIST STATS"),
    todo("todo")
{
    add(&todo);
}

} // end namespace CSCreator

#include "cseditor/components/equipment.h"
#include "cseditor/components/component.h"

namespace CSEditor {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

Equipment::Equipment(CS::Equipment *equipment, QWidget *parent):
    Component(equipment->getTitle(), parent),
    equipment(equipment)
{
    bodyAdd(&addItemBtn);
}

// TODO: addItem

} // end namespace CSEditor

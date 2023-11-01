#ifndef EQUIPMENTCREATIONPOPUP_H
#define EQUIPMENTCREATIONPOPUP_H

#include "cscreatorpopup.h"

#include <QLineEdit>

/* NOTE: I'm not sure if this thing will work like this, it's not intuitive.
 *
 * TODO: This should allow to add a placeholder for equipment. When it's added
 * to the sheet we can choose the type of placeholder we will have (standard
 * equipement, weapon list, ...).
 * The type of equipment determin the shape of the elements in the placeholder.
 * For instance, if we have the weapon type, the place holder will be able to
 * contain a list of elements composed of a name, a bonus to dice attack and a
 * damage dice, whereas if the type is a standard item, the elements in the
 * placeholder will be composed of a name, a quantity and a weight.
 */

class EquipmentCreationPopup : public CSCreatorPopup
{
    Q_OBJECT
public:
    EquipmentCreationPopup();
    QString getName() const { return nameEdit.text(); }

private:
    QLineEdit nameEdit;
};

#endif // EQUIPMENTCREATIONPOPUP_H

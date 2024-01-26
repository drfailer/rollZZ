#ifndef CSEDITOR_EQUIPMENTPOPUP_H
#define CSEDITOR_EQUIPMENTPOPUP_H

#include "tools/popup.h"

#include <QLineEdit>
#include <QRadioButton>
#include <QSpinBox>

namespace CSCreator {

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

class EquipmentPopup : public Tools::Popup {
    Q_OBJECT
public:
    EquipmentPopup(bool useWeight = true, int maxWeight = 0, int maxItems = 0);
    bool getUseWeight() const { return useWeightRBtn.isChecked(); }
    int getMaxWeight() const { return maxWeightBox.value(); }
    int getMaxItems() const { return maxItemsBox.value(); }

private:
    QRadioButton useWeightRBtn;
    QSpinBox maxWeightBox;
    QSpinBox maxItemsBox;
};

} // end namespace CSCreator

#endif // EQUIPMENTPOPUP_H

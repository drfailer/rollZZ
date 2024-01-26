#include "bonusstat.h"
#include <iostream>

namespace CSEditor {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

BonusStat::BonusStat(CS::BonusStat *bonuStat_in, QWidget *parent):
    BasicStat(static_cast<CS::BasicStat*>(bonuStat_in), parent),
    bonusEdit(this),
    bonusStat(bonuStat_in)

{
    bonusEdit.setMinimum(-100);
    bonusEdit.setValue(bonusStat->getBonusValue());
    bodyAdd("Bonus:", &bonusEdit);

    connect(&bonusEdit, &QSpinBox::valueChanged, this, [&](int newValue) {
                this->bonusStat->setBonusValue(newValue);
            });
}

} // end namespace CSEditor

#include "bonusstat.h"
#include "bonusstatpopup.h"
#include "component.h"

namespace CSCreator {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

BonusStat::BonusStat(CS::BonusStat *bonuStat, int valueMax, Dice dice, const QString& name, QWidget *parent):
    BasicStat(nullptr, valueMax, dice, name, "Bonus stat", parent),
    bonusStat(bonuStat)
{

}

/******************************************************************************/
/*                                  settings                                  */
/******************************************************************************/

genSettingsPopup(BonusStat, bonusStatPopup, BonusStatPopup, {
    valueMax = bonusStatPopup->getMaxValue();
    dice = bonusStatPopup->getDice();
    name = bonusStatPopup->getName();
    updateLabels();
}, name, valueMax, dice);

} // end namespace CSCreator

#include "bonusstat.h"
#include "bonusstatpopup.h"
#include "component.h"

namespace CSCreator {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

BonusStat::BonusStat(CS::BonusStat *bonuStat_in, QWidget *parent):
    BasicStat(static_cast<CS::BasicStat*>(bonuStat_in), "Bonus stat", parent),
    bonusStat(bonuStat_in)
{

}

/******************************************************************************/
/*                                  settings                                  */
/******************************************************************************/

genSettingsPopup(BonusStat, bonusStatPopup, BonusStatPopup, {
    update(bonusStatPopup->getMaxValue(), bonusStatPopup->getDice(), bonusStatPopup->getName());
}, bonusStat->getTitle(), bonusStat->getValueMax(), bonusStat->getDice());

} // end namespace CSCreator

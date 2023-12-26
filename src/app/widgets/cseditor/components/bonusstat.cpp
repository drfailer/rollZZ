#include "bonusstat.h"
#include "bonusstatpopup.h"
#include "component.h"

namespace CSEditor {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

BonusStat::BonusStat(CS::BonusStat *bonuStat_in, QWidget *parent):
    BasicStat(static_cast<CS::BasicStat*>(bonuStat_in), parent),
    bonusStat(bonuStat_in)
{
}

} // end namespace CSEditor

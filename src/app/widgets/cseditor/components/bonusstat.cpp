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
    bodyAdd(&bonusEdit);
}

} // end namespace CSEditor
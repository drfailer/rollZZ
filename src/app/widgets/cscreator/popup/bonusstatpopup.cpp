#include "bonusstatpopup.h"

namespace CSCreator {

BonusStatPopup::BonusStatPopup():
    BasicStatPopup("BONUS STAT")
{

}

BonusStatPopup::BonusStatPopup(const QString &name, int maxValue, Dice dice):
    BasicStatPopup(name, maxValue, dice)
{

}

} // end namespace CSCreator

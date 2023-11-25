#include "bonusstat.h"
#include "bonusstatpopup.h"
#include "component.h"

namespace CSCreator {

BonusStat::BonusStat(int valueMax, Dice dice, const QString& name, QWidget *parent):
    BasicStat(valueMax, dice, name, "Bonus stat", parent)
{

}

genSettingsPopup(BonusStat, bonusStatPopup, BonusStatPopup, {
    valueMax = bonusStatPopup->getMaxValue();
    dice = bonusStatPopup->getDice();
    name = bonusStatPopup->getName();
    updateLabels();
}, name, valueMax, dice);

} // end namespace CSCreator

#include "bonusstat.h"
#include "bonusstatpopup.h"

namespace CSCreator {

BonusStat::BonusStat(int valueMax, Dice dice, const QString& name, QWidget *parent):
    BasicStat(valueMax, dice, name, "Bonus stat", parent)
{

}

void BonusStat::settingsPopup()
{
    if (bonusStatPopup == nullptr) {
        bonusStatPopup = new BonusStatPopup(name, valueMax, dice);
    }
    bonusStatPopup->show();
    connect(bonusStatPopup, &BonusStatPopup::confirm, this, [&](bool confirm) {
        if (confirm) {
            valueMax = bonusStatPopup->getMaxValue();
            dice = bonusStatPopup->getDice();
            name = bonusStatPopup->getName();
            updateLabels();
        }
        delete bonusStatPopup;
        bonusStatPopup = nullptr;
    });
}

} // end namespace CSCreator

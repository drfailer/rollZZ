#include "bonusstat.h"
#include "bonusstatpopup.h"

namespace CSCreator {

BonusStat::BonusStat(int valueMax, Dice dice, const QString& title, QWidget *parent):
    BasicStat(valueMax, dice, title, parent)
{

}

void BonusStat::settingsPopup()
{
    if (bonusStatPopup == nullptr) {
        bonusStatPopup = new BonusStatPopup(getTitle(), valueMax, dice);
    }
    bonusStatPopup->show();
    connect(bonusStatPopup, &BonusStatPopup::confirm, this, [&](bool confirm) {
        if (confirm) {
            valueMax = bonusStatPopup->getMaxValue();
            dice = bonusStatPopup->getDice();
            updateLabels();
            setTitle("Bonus stat: " + bonusStatPopup->getName());
        }
        delete bonusStatPopup;
        bonusStatPopup = nullptr;
    });
}

} // end namespace CSCreator

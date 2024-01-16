#include "bonusstat.h"
#include <QList>

namespace CS {

/******************************************************************************/
/*                              static variables                              */
/******************************************************************************/

QList<BonusStat*> BonusStat::elements;

/******************************************************************************/
/*                          constructor & destructor                          */
/******************************************************************************/

BonusStat::BonusStat(const QString& title, int _bonusValue, int value, int valueMax, Dice dice):
    BasicStat(title, value, valueMax, dice),
    SERIALIZER(bonusValue),
    bonusValue(_bonusValue)
{
    elements.push_back(this);
}

BonusStat::~BonusStat() {
    elements.removeOne(this);
}

/******************************************************************************/
/*                                    roll                                    */
/******************************************************************************/

int BonusStat::roll() const {
    int diceResult = BasicStat::roll();

    // critical miss configurable ?
    if (diceResult == 1) {
        return 1;
    }
    return diceResult + bonusValue;
}

} // end namespace CS

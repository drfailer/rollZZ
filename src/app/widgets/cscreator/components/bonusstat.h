#ifndef BONUSSTAT_H
#define BONUSSTAT_H

#include "basicstat.h"

namespace CSCreator {

class BonusStatPopup;

class BonusStat : public BasicStat
{
    Q_OBJECT
public:
    BonusStat(int valueMax, Dice dice, const QString& name, QWidget *parent = nullptr);
    void settingsPopup() override;

private:
    BonusStatPopup *bonusStatPopup;
};

} // end namespace CSCreator

#endif // BONUSSTAT_H

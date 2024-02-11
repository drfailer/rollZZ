#ifndef CSCREATOR_BONUSSTAT_H
#define CSCREATOR_BONUSSTAT_H

#include "basicstat.h"
#include "CS/bonusstat.h"

namespace CSCreator {

class BonusStatPopup;

class BonusStat : public BasicStat
{
    Q_OBJECT
public:
    BonusStat(CS::BonusStat *bonuStat, QWidget *parent = nullptr);
    void settingsPopup() override;

private:
    BonusStatPopup *bonusStatPopup = nullptr;
    CS::BonusStat *bonusStat = nullptr;
};

} // end namespace CSCreator

#endif // BONUSSTAT_H

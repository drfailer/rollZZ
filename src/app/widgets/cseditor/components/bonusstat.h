#ifndef CSEDITOR_BONUSSTAT_H
#define CSEDITOR_BONUSSTAT_H

#include "basicstat.h"
#include "CS/bonusstat.h"

namespace CSEditor {

class BonusStatPopup;

class BonusStat : public BasicStat
{
    Q_OBJECT
public:
    BonusStat(CS::BonusStat *bonuStat, QWidget *parent = nullptr);

private:
    QSpinBox bonusEdit;
    CS::BonusStat *bonusStat = nullptr;
};

} // end namespace CSEditor

#endif // BONUSSTAT_H

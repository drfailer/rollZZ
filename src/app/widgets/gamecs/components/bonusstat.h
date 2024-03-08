#ifndef GAMECS_BONUSSTAT_H
#define GAMECS_BONUSSTAT_H

#include "CS/bonusstat.h"
#include "basicstat.h"

#include <QPushButton>

namespace GameCS {

class BonusStatPopup;

class BonusStat : public BasicStat {
    Q_OBJECT
  public:
    BonusStat(CS::BonusStat *bonuStat, QWidget *parent = nullptr);

  signals:
    void rolled(QString);

  private:
    CS::BonusStat *bonusStat = nullptr;
    QPushButton *rollBtn = nullptr;
};

} // end namespace GameCS

#endif // BONUSSTAT_H

#ifndef CS_BONUSSTAT_H
#define CS_BONUSSTAT_H

#include "basicstat.h"
#include "dice.h"
#include "serializer.hpp"

namespace CS {

class BonusStat : public BasicStat {
    SERIALIZABLE_SUPER(BasicStat, int);
  public:
    BonusStat(const QString &title = "name", int bonusValue = 0, int value = 8,
              int valueMax = 20, Dice dice = Dice());
    int roll() const;

    /* accessors **************************************************************/
    int getBonusValue() const { return bonusValue; }
    void setBonusValue(int newBonusValue) { bonusValue = newBonusValue; }

  private:
    int bonusValue;
};

} // end namespace CS

#endif // BONUSSTAT_H

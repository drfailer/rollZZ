#include "bonusstat.h"
#include <iostream>

namespace GameCS {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

BonusStat::BonusStat(CS::BonusStat *bonuStat_in, QWidget *parent):
    BasicStat(static_cast<CS::BasicStat*>(bonuStat_in), parent),
    bonusStat(bonuStat_in),
    rollBtn(new QPushButton("roll", this))

{
    bodyAdd("Bonus:", new QLabel(QString::number(bonusStat->getBonusValue()), this));
    bodyAdd(rollBtn);

    connect(rollBtn, &QPushButton::clicked, this, [&]() {
                /* emit rolled(this->bonusStat->roll()); */
                std::cout << this->bonusStat->roll() << std::endl;
            });
}

} // end namespace GameCS

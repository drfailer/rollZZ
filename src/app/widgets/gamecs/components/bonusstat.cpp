#include "bonusstat.h"
#include <iostream>

namespace GameCS {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

BonusStat::BonusStat(CS::BonusStat *bonuStat_in, QWidget *parent)
    : BasicStat(static_cast<CS::BasicStat *>(bonuStat_in), parent),
      bonusStat(bonuStat_in),
      rollBtn(new QPushButton("roll", this))
{
    bodyAdd("Bonus:",
            new QLabel(QString::number(bonusStat->getBonusValue()), this));
    bodyAdd(rollBtn);

    connect(rollBtn, &QPushButton::clicked, this, [&]() {
        QString message = "rolled " + this->bonusStat->getTitle() + ": " +
                          QString::number(this->bonusStat->roll());
        emit rolled(message);
        std::cout << message.toStdString() << std::endl;
    });
}

} // end namespace GameCS

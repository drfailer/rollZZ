#include "gamecs/components/basicstat.h"
#include <QStringBuilder>

namespace GameCS {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

BasicStat::BasicStat(CS::BasicStat *basicStat, QWidget *parent):
    Component(basicStat->getTitle(), parent),
    basicStat(basicStat)
{
    bodyAdd("Value:", new QLabel(QString::number(basicStat->getValue()), this));

    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #202020; }"
                  );
}

} // end namespace GameCS

#include "gamecs/components/liststat.h"

#include "CS/liststat.h"
#include "gamecs/components/caracteristic.h"

namespace  GameCS {

/******************************************************************************/
/*                         constructors & destructors                         */
/******************************************************************************/

ListStat::ListStat(CS::ListStat *listStat, QWidget *parent):
    Component(listStat->getTitle(), parent),
    listStat(listStat)
{
    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #202020; }"
                  );

    for (int i = 0; i < listStat->count(); ++i) {
        bodyAdd(new Caracteristic(&listStat->at(i), this));
    }
}

ListStat::~ListStat()
{
}

} // end namespace GameCS

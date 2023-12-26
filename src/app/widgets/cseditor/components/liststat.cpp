#include "cseditor/components/liststat.h"

#include "CS/liststat.h"

namespace  CSEditor {

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

    // TODO: add skill edit for each skill
    /* bodyAdd(&newSkillEdit); */
}

ListStat::~ListStat()
{
}

} // end namespace CSEditor

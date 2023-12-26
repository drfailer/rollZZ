#include "cseditor/components/basicstat.h"
#include <QStringBuilder>

namespace CSEditor {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

BasicStat::BasicStat(CS::BasicStat *basicStat, QWidget *parent):
    Component(basicStat->getTitle(), parent),
    valueEdit(this)
{
    valueEdit.setMaximum(basicStat->getValueMax());
    bodyAdd(&valueEdit);

    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #202020; }"
                  );
}

// TODO: update the basicStat

} // end namespace CSEditor

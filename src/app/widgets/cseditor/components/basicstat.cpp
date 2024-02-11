#include "cseditor/components/basicstat.h"
#include <QStringBuilder>

namespace CSEditor {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

BasicStat::BasicStat(CS::BasicStat *basicStat, QWidget *parent):
    Component(basicStat->getTitle(), parent),
    valueEdit(this),
    basicStat(basicStat)
{
    valueEdit.setMinimum(-100);
    valueEdit.setMaximum(basicStat->getValueMax());
    valueEdit.setValue(basicStat->getValue());
    bodyAdd("Value:", &valueEdit);

    connect(&valueEdit, &QSpinBox::valueChanged, this, [&](int newValue){
                this->basicStat->setValue(newValue);
            });
    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #202020; }"
                  );
}

// TODO: update the basicStat

} // end namespace CSEditor

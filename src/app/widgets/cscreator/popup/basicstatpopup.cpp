#include "basicstatpopup.h"
#include <iostream>

namespace CSCreator {

BasicStatPopup::BasicStatPopup(const QString &title):
    CSCreatorPopup(title),
    nameEdit("stat name"),
    valueMaxEdit(this),
    diceEditWgt(this)
{
    // TODO: create a form
    valueMaxEdit.setValue(20);
    add(&nameEdit);
    add(&valueMaxEdit);
    add(&diceEditWgt);
}

BasicStatPopup::BasicStatPopup():
    BasicStatPopup("STATISTIC")
{
}

} // end namespace CSCreator

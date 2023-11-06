#include "basicstatpopup.h"
#include <iostream>

BasicStatPopup::BasicStatPopup(const QString &title):
    CSCreatorPopup(title),
    nameEdit("stat name"),
    valueMaxEdit(this),
    diceEditWgt(this)
{

}

BasicStatPopup::BasicStatPopup():
    BasicStatPopup("STATISTIC")
{
}

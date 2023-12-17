#include "basicstat.h"
#include "basicstatpopup.h"
#include <QStringBuilder>

namespace CSCreator {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

BasicStat::BasicStat(CS::BasicStat *basicStat, int valueMax, Dice dice, const QString& name, const QString &title, QWidget *parent):
    Component(title, parent),
    basicStat(basicStat)
{
    update(valueMax, dice, name);

    bodyAdd(&nameLabel);
    bodyAdd(&valueMaxLabel);
    bodyAdd(&diceLabel);

    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #202020; }"
                  );
    connectSettings();
}

BasicStat::BasicStat(CS::BasicStat *basicStat, int valueMax, Dice dice, const QString &name, QWidget *parent):
    BasicStat(basicStat, valueMax, dice, name, "Basic stat", parent)
{

}

/******************************************************************************/
/*                                  settings                                  */
/******************************************************************************/

genSettingsPopup(BasicStat, basicStatPopup, BasicStatPopup, {
    update(basicStatPopup->getMaxValue(), basicStatPopup->getDice(), basicStatPopup->getName());
}, basicStat->getTitle(), basicStat->getValueMax(), basicStat->getDice())

void BasicStat::update(int valueMax, Dice dice, const QString& name) {
    basicStat->setValueMax(valueMax);
    basicStat->setTitle(name);
    basicStat->setDice(dice);
    valueMaxLabel.setText("max value: " + QString::number(valueMax));
    diceLabel.setText("dice: " + QString::number(dice.getDiceNumber()) + "d" + QString::number(dice.getFaces()));
    nameLabel.setText("name: " + name);
}

} // end namespace CSCreator

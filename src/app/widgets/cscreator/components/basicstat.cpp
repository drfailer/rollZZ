#include "basicstat.h"

namespace CSCreator {

BasicStat::BasicStat(int valueMax, Dice dice, const QString& title, QWidget *parent):
    Component(title, parent)
{
    QTextStream s;

    s << "max value: " << valueMax;

    valueMaxLabel.setText(*s.string());

    s.reset();
    s << "dice: " << dice.getDiceNumber() << "d" << dice.getFaces();
    diceLabel.setText(*s.string());
}

} // end namespace CSCreator

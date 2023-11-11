#include "basicstat.h"
#include "basicstatpopup.h"
#include <QStringBuilder>
#include <iostream>

namespace CSCreator {

BasicStat::BasicStat(int valueMax, Dice dice, const QString& name, const QString &title, QWidget *parent):
    Component(title, parent),
    name(name),
    valueMax(valueMax),
    dice(dice)
{
    updateLabels();

    bodyAdd(&nameLabel);
    bodyAdd(&valueMaxLabel);
    bodyAdd(&diceLabel);

    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #202020; }"
                  );
    connectSettingFunction(this, [&]() { this->settingsPopup(); });
}

BasicStat::BasicStat(int valueMax, Dice dice, const QString &name, QWidget *parent):
    BasicStat(valueMax, dice, name, "Bonus stat", parent)
{

}

void BasicStat::settingsPopup()
{
    if (basicStatPopup == nullptr) {
        basicStatPopup = new BasicStatPopup(name, valueMax, dice);
    }
    basicStatPopup->show();
    connect(basicStatPopup, &BasicStatPopup::confirm, this, [&](bool confirm) {
        if (confirm) {
            valueMax = basicStatPopup->getMaxValue();
            dice = basicStatPopup->getDice();
            name = basicStatPopup->getName();
            updateLabels();
        }
        delete basicStatPopup;
        basicStatPopup = nullptr;
    });
}

void BasicStat::updateLabels()
{
    valueMaxLabel.setText("max value: " + QString::number(valueMax));
    diceLabel.setText("dice: " + QString::number(dice.getDiceNumber()) + "d" + QString::number(dice.getFaces()));
    nameLabel.setText("name: " + name);
}

} // end namespace CSCreator

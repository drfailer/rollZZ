#include "basicstat.h"
#include "basicstatpopup.h"
#include <QStringBuilder>
#include <iostream>

namespace CSCreator {

BasicStat::BasicStat(int valueMax, Dice dice, const QString& title, QWidget *parent):
    Component(title, parent),
    valueMax(valueMax),
    dice(dice)
{
    updateLabels();

    bodyAdd(&valueMaxLabel);
    bodyAdd(&diceLabel);

    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #202020; }"
                  );
    connectSettingFunction(this, [&]() { settingsPopup(); });
}

void BasicStat::settingsPopup()
{
    if (basicStatPopup == nullptr) {
        basicStatPopup = new BasicStatPopup(getTitle(), valueMax, dice);
    }
    basicStatPopup->show();
    connect(basicStatPopup, &BasicStatPopup::confirm, this, [&](bool confirm) {
        if (confirm) {
            valueMax = basicStatPopup->getMaxValue();
            dice = basicStatPopup->getDice();
            updateLabels();
            setTitle(basicStatPopup->getName());
        }
        delete basicStatPopup;
        basicStatPopup = nullptr;
    });
}

void BasicStat::updateLabels()
{
    QString valueMaxStr;
    QString diceStr;

    valueMaxStr = "max value: " + QString::number(valueMax);
    valueMaxLabel.setText(valueMaxStr);

    diceStr = "dice: " + QString::number(dice.getDiceNumber()) + "d" + QString::number(dice.getFaces());
    diceLabel.setText(diceStr);
}

} // end namespace CSCreator

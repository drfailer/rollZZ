#ifndef BASICSTAT_H
#define BASICSTAT_H

#include "component.h"

#include <QLabel>
#include <QWidget>
#include <QString>
#include <dice.h>

namespace CSCreator {

class BasicStatPopup;

class BasicStat : public Component
{
    Q_OBJECT
public:
    explicit BasicStat(int valueMax, Dice dice, const QString& title, QWidget *parent = nullptr);

private slots:
    void settingsPopup();

private:
    QLabel valueMaxLabel;
    QLabel diceLabel;
    int valueMax;
    Dice dice; // NOTE: it would be better to find an alternative to this
    BasicStatPopup *basicStatPopup = nullptr;

    void updateLabels();
};

} // end namespace CSCreator

#endif // BASICSTAT_H

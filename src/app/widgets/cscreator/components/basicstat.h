#ifndef BASICSTAT_H
#define BASICSTAT_H

#include "component.h"

#include <QLabel>
#include <QWidget>
#include <QString>
#include <dice.h>

namespace CSCreator {

class BasicStat : public Component
{
    Q_OBJECT
public:
    explicit BasicStat(int valueMax, Dice dice, const QString& title, QWidget *parent = nullptr);

private:
    QLabel valueMaxLabel;
    QLabel diceLabel;
};

} // end namespace CSCreator

#endif // BASICSTAT_H

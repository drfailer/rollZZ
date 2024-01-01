#ifndef CSEDITOR_BASICSTATPOPUP_H
#define CSEDITOR_BASICSTATPOPUP_H

#include "cscreatorpopup.h"
#include "diceedit.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QWidget>
#include <dice.h>

namespace CSCreator {

class BasicStatPopup : public CSCreatorPopup
{
    Q_OBJECT
public:
    BasicStatPopup();
    BasicStatPopup(const QString &name, int maxValue, Dice dice, const QString& title = "STATISTIC");
    QString getName() const { return nameEdit.text(); }
    int getMaxValue() const { return valueMaxEdit.value(); }
    Dice getDice() const { return Dice(diceEditWgt.getFaces(), diceEditWgt.getNumber()); }

protected:
    BasicStatPopup(const QString& title);

private:
    QLineEdit nameEdit;
    QSpinBox valueMaxEdit;
    DiceEdit diceEditWgt;
};

} // end namespace CSCreator

#endif // BASICSTATPOPUP_H

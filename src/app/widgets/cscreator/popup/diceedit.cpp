#include "diceedit.h"
#include <qlabel.h>

DiceEdit::DiceEdit(bool useBonus, QWidget *parent):
    QWidget(parent),
    diceFaces(this),
    diceNumber(this),
    bonusEdit(this)
{
    diceFaces.setValue(20);
    diceNumber.setValue(1);
    // dice edit: 1 d 20
    mainLyt.addWidget(&diceNumber);
    mainLyt.addWidget(new QLabel("d"));
    mainLyt.addWidget(&diceFaces);

    if (useBonus) {
        bonusEdit.setMinimum(0);
        mainLyt.addWidget(new QLabel("+"));
        mainLyt.addWidget(&bonusEdit);
    } else {
        bonusEdit.hide();
    }
    mainLyt.setAlignment(Qt::AlignLeft);
    setLayout(&mainLyt);
}

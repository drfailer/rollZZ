#include "diceedit.h"

DiceEdit::DiceEdit(QWidget *parent):
    QWidget(parent),
    diceLabel("d"),
    diceFaces(this),
    diceNumber(this)
{
    diceFaces.setValue(20);
    diceNumber.setValue(1);
    // dice edit: 1 d 20
    mainLyt.addWidget(&diceNumber);
    mainLyt.addWidget(&diceLabel);
    mainLyt.addWidget(&diceFaces);
    mainLyt.setAlignment(Qt::AlignLeft);
    setLayout(&mainLyt);
}

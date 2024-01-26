#include "diceedit.h"
#include <QLabel>

DiceEdit::DiceEdit(const Dice& dice, int bonusValue, bool useBonus, QWidget *parent):
    QWidget(parent),
    diceFacesEdit(this),
    diceNumberEdit(this),
    bonusEdit(this)
{
    diceFacesEdit.setValue(dice.getFaces());
    diceNumberEdit.setValue(dice.getDiceNumber());
    bonusEdit.setValue(bonusValue);
    // dice edit: 1 d 20
    mainLyt.addWidget(&diceNumberEdit);
    mainLyt.addWidget(new QLabel("d"));
    mainLyt.addWidget(&diceFacesEdit);

    if (useBonus) {
        bonusEdit.setMinimum(0);
        mainLyt.addWidget(new QLabel("+"));
        mainLyt.addWidget(&bonusEdit);
    } else {
        bonusEdit.hide();
    }
    mainLyt.setAlignment(Qt::AlignLeft);
    setLayout(&mainLyt);

    // connects
    connect(&diceNumberEdit, &QSpinBox::valueChanged, this, [&](int newDiceNumber) {
                emit diceChanged(Dice(this->diceFacesEdit.value(), newDiceNumber));
            });
    connect(&diceFacesEdit, &QSpinBox::valueChanged, this, [&](int newDiceFaces) {
                emit diceChanged(Dice(newDiceFaces, this->diceNumberEdit.value()));
            });
    connect(&bonusEdit, &QSpinBox::valueChanged, this, [&](int newBonus) {
                emit bonusChanged(newBonus);
            });

}

DiceEdit::DiceEdit(QWidget *parent): DiceEdit(Dice(), 0, false, parent) {
}

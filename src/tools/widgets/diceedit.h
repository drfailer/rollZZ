#ifndef CSEDITOR_DICEEDIT_H
#define CSEDITOR_DICEEDIT_H

#include "dice.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QWidget>

class DiceEdit : public QWidget {
    Q_OBJECT
  public:
    DiceEdit(const Dice& dice, int bonusValue, bool useBonus = false, QWidget *parent = nullptr);
    DiceEdit(QWidget *parent = nullptr);
    int getFaces() const { return diceFacesEdit.value(); }
    int getNumber() const { return diceNumberEdit.value(); }
    void setFaces(int newFaces) { diceFacesEdit.setValue(newFaces); }
    void setNumber(int newDiceNumber) { diceNumberEdit.setValue(newDiceNumber); }

signals:
    void diceChanged(const Dice dice);
    void bonusChanged(int newValue);

  private:
    QHBoxLayout mainLyt;
    QSpinBox diceFacesEdit;
    QSpinBox diceNumberEdit;
    QSpinBox bonusEdit;
};

#endif // DICEEDIT_H

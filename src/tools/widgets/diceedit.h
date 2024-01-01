#ifndef CSEDITOR_DICEEDIT_H
#define CSEDITOR_DICEEDIT_H

#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QWidget>

class DiceEdit : public QWidget {
    Q_OBJECT
  public:
    DiceEdit(bool useBonus = false, QWidget *parent = nullptr);
    int getFaces() const { return diceFaces.value(); }
    int getNumber() const { return diceNumber.value(); }
    void setFaces(int newFaces) { diceFaces.setValue(newFaces); }
    void setNumber(int newDiceNumber) { diceNumber.setValue(newDiceNumber); }

  private:
    QHBoxLayout mainLyt;
    QSpinBox diceFaces;
    QSpinBox diceNumber;
    QSpinBox bonusEdit;
};

#endif // DICEEDIT_H

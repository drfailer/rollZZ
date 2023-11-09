#ifndef DICEEDIT_H
#define DICEEDIT_H

#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QWidget>

class DiceEdit : public QWidget
{
    Q_OBJECT
public:
    explicit DiceEdit(QWidget *parent = nullptr);
    int getFaces() const { return diceFaces.value(); }
    int getNumber() const { return diceNumber.value(); }
    void setFaces(int newFaces) { diceFaces.setValue(newFaces); }
    void setNumber(int newDiceNumber) { diceNumber.setValue(newDiceNumber); }

private:
    QHBoxLayout mainLyt;
    QLabel diceLabel;
    QSpinBox diceFaces;
    QSpinBox diceNumber;
};

#endif // DICEEDIT_H

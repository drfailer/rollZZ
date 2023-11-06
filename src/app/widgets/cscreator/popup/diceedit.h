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

private:
    QHBoxLayout mainLyt;
    QLabel diceLabel;
    QSpinBox diceFaces;
    QSpinBox diceNumber;
};

#endif // DICEEDIT_H

#ifndef BASICSTATPOPUP_H
#define BASICSTATPOPUP_H

#include "cscreatorpopup.h"
#include "diceedit.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QWidget>

class BasicStatPopup : public CSCreatorPopup
{
    Q_OBJECT
public:
    explicit BasicStatPopup();
    QString getName() const { return nameEdit.text(); }
    int getValue() const { return valueMaxEdit.value(); }

protected:
    BasicStatPopup(const QString& title);

private:
    QLineEdit nameEdit;
    QSpinBox valueMaxEdit;
    DiceEdit diceEditWgt;
};

#endif // BASICSTATPOPUP_H

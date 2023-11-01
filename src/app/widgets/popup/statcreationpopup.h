#ifndef STATCREATIONPOPUP_H
#define STATCREATIONPOPUP_H

#include "cscreatorpopup.h"

#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QWidget>

class StatCreationPopup : public CSCreatorPopup
{
    Q_OBJECT
public:
    explicit StatCreationPopup();
    QString getName() const { return nameEdit.text(); }
    int getValue() const { return valueMaxEdit.value(); }

private:
    QLineEdit nameEdit;
    QSpinBox valueMaxEdit;
    QComboBox diceEdit;
};

#endif // STATCREATIONPOPUP_H

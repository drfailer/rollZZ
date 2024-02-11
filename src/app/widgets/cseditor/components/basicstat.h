#ifndef CSEDITOR_BASICSTAT_H
#define CSEDITOR_BASICSTAT_H

#include "CS/basicstat.h"
#include "component.h"

#include <QLabel>
#include <QWidget>
#include <dice.h>
#include <QSpinBox>
#include <QBoxLayout>

namespace CSEditor {

class BasicStat : public Component
{
    Q_OBJECT
public:
    BasicStat(CS::BasicStat *basicStat, QWidget *parent = nullptr);
    virtual ~BasicStat() {}

protected:
    QSpinBox valueEdit;
    CS::BasicStat *basicStat = nullptr;
};

} // end namespace CSEditor

#endif // BASICSTAT_H

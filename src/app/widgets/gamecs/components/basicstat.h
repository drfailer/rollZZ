#ifndef GAMECS_BASICSTAT_H
#define GAMECS_BASICSTAT_H

#include "CS/basicstat.h"
#include "component.h"

#include <QWidget>
#include <QBoxLayout>

namespace GameCS {

class BasicStat : public Component
{
    Q_OBJECT
public:
    BasicStat(CS::BasicStat *basicStat, QWidget *parent = nullptr);
    virtual ~BasicStat() {}

protected:
    CS::BasicStat *basicStat = nullptr;
};

} // end namespace GameCS

#endif // BASICSTAT_H

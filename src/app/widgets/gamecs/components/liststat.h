#ifndef GAMECS_LISTSTAT_H
#define GAMECS_LISTSTAT_H

#include "component.h"
#include "CS/liststat.h"

namespace GameCS {

class SkillWgt;

class ListStat : public Component
{
    Q_OBJECT
public:
    ListStat(CS::ListStat *listStat, QWidget* parent = nullptr);
    ~ListStat();

private:
    CS::ListStat *listStat = nullptr;
};

} // end namespace GameCS

#endif // LISTSTAT_H

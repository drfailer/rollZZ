#ifndef CSEDITOR_LISTSTAT_H
#define CSEDITOR_LISTSTAT_H

#include "tools/component.h"
#include "CS/liststat.h"

namespace CSEditor {

class SkillWgt;

class ListStat : public Tools::Component
{
    Q_OBJECT
public:
    ListStat(CS::ListStat *listStat, QWidget* parent = nullptr);
    ~ListStat();

private:
    CS::ListStat *listStat = nullptr;
};

} // end namespace CSEditor

#endif // LISTSTAT_H

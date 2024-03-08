#ifndef GAMECS_LISTSTAT_H
#define GAMECS_LISTSTAT_H

#include "CS/liststat.h"
#include "tools/component.h"

namespace GameCS {

class SkillWgt;

class ListStat : public Tools::Component {
    Q_OBJECT
  public:
    ListStat(CS::ListStat *listStat, QWidget *parent = nullptr);
    ~ListStat();

  signals:
    void rolled(QString message);

  private:
    CS::ListStat *listStat = nullptr;
};

} // end namespace GameCS

#endif // LISTSTAT_H

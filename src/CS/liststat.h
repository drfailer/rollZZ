#ifndef CS_LISTSTAT_H
#define CS_LISTSTAT_H

#include "caracteristic.h"
#include "component.h"

#include <QList>

namespace CS {

class ListStat : public Component {
  public:
    using const_iterator = typename QList<Caracteristic>::const_iterator;
    using Component::Component;
    ListStat();

    /* accessors **************************************************************/
    void addStat(Caracteristic newStat) { stats.push_back(newStat); }
    void removeStat(int index) { stats.remove(index); }
    void clearStats() { stats.clear(); }
    Caracteristic &at(int index) { return stats[index]; }
    const_iterator begin() const { return stats.begin(); }
    const_iterator end() const { return stats.end(); }
    int count() const { return stats.count(); }

  private:
    QList<Caracteristic> stats;
};

} // end namespace CS

#endif // LISTSTAT_H

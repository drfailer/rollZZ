#ifndef CS_LISTSTAT_H
#define CS_LISTSTAT_H

#include "caracteristic.h"
#include "component.h"

#include <QList>

namespace CS {

class ListStat : public Component {
    SERIALIZABLE_SUPER(Component, QList<Caracteristic>);
  public:
    ListStat();

    /* accessors **************************************************************/
    void addStat(Caracteristic newStat) { stats.push_back(newStat); }
    void removeStat(int index) { stats.remove(index); }
    void clearStats() { stats.clear(); }
    const QList<Caracteristic>& getStats() const { return stats; }
    Caracteristic &at(int index) { return stats[index]; }
    int count() const { return stats.count(); }

  private:
    QList<Caracteristic> stats;
};

} // end namespace CS

#endif // LISTSTAT_H

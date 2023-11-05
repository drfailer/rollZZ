#ifndef LISTSTAT_H
#define LISTSTAT_H

#include "caracteristic.h"
#include "component.h"

#include <QList>

namespace CS {

class ListStat : public Component
{
public:
    using Component::Component;
    ListStat();

    /* accessors ***************************************************************/
    void addStat(Caracteristic newStat) { stats.push_back(newStat); }
    void removeStat(int index) { stats.remove(index); }
    Caracteristic& at(int index) { return stats[index]; }
    // TODO: move stats in the list

private:
    QList<Caracteristic> stats;
};

} // end namespace CS

#endif // LISTSTAT_H

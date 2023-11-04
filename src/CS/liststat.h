#ifndef LISTSTAT_H
#define LISTSTAT_H

#include "caracteristic.h"
#include "component.h"

#include <QList>

namespace CS {

class ListStat : public Component
{
public:
    ListStat();

private:
    QList<Caracteristic> stats;
};

} // end namespace CS

#endif // LISTSTAT_H

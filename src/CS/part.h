#ifndef CS_PART_H
#define CS_PART_H

#include "section.h"

#include <QList>
#include <QString>

namespace CS {
class Part
{
public:
    Part(const QString& name);

    /* accessors ***************************************************************/

private:
    QString name;
    QList<Section> sections;
};
}

#endif // PART_H

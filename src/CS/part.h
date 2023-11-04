#ifndef PART_H
#define PART_H

#include "section.h"

#include <QList>
#include <QString>

namespace CS {
class Part
{
public:
    Part(const QString& name);

private:
    QString name;
    QList<Section> sections;
};
}

#endif // PART_H

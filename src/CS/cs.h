#ifndef CS_H
#define CS_H

#include "part.h"

#include <QList>


namespace CS {
class CS
{
public:
    CS() = default;

    /* methods **********************************************/
    void addPart(Part part) { parts.push_back(part); }
    // TODO: add a way to move parts

private:
    QList<Part> parts;
};
}

#endif // CS_H

#ifndef CS_CS_H
#define CS_CS_H

#include "part.h"

#include <QList>


namespace CS {

class CS
{
public:
    CS() = default;
    ~CS();

    /* methods **********************************************/
    void addPart(Part* part) { parts.push_back(part); }
    const QList<Part*>& getParts() const { return parts; }
    // TODO: add a way to move parts

private:
    QList<Part*> parts;
};

}

#endif // CS_H

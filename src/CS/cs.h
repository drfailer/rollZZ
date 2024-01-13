#ifndef CS_CS_H
#define CS_CS_H

#include "part.h"
#include "serializable.hpp"

#include <QList>

namespace CS {

class CS {
    SERIALIZABLE(QList<Part *>);

  public:
    CS() : SERIALIZER(parts) {}
    ~CS();

    /* methods ****************************************************************/
    void addPart(Part *part) { parts.push_back(part); }
    const QList<Part *> &getParts() const { return parts; }
    void clearParts();
    // TODO: add a way to move parts

  private:
    QList<Part *> parts;
};

} // namespace CS

#endif // CS_H

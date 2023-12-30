#ifndef CS_DESCRIPTOR_H
#define CS_DESCRIPTOR_H

#include "component.h"

#include <QString>

// TODO: add descriptor types (line edit, big, ...)

namespace CS {

class Descriptor : public Component
{
public:
    using Component::Component;
    Descriptor();

    /* accessors ***************************************************************/
    QString getDescription() const { return description; }
    void setDescription(const QString &newDescription) { description = newDescription; }

private:
    QString description;
};

} // end namespace CS

#endif // DESCRIPTOR_H

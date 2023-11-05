#ifndef DESCRIPTOR_H
#define DESCRIPTOR_H

#include "component.h"

#include <QString>

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

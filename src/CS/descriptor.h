#ifndef CS_DESCRIPTOR_H
#define CS_DESCRIPTOR_H

#include "component.h"
#include "descriptortypes.h"
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
    void setType(DescriptorTypes type) { this->type = type; }
    DescriptorTypes getType() const { return type; }

private:
    QString description;
    DescriptorTypes type;
};

} // end namespace CS

#endif // DESCRIPTOR_H

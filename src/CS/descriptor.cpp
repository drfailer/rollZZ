#include "descriptor.h"

namespace CS {

Descriptor::Descriptor(const QString& title):
    Component(title),
    SERIALIZER(description, type)
{

}

} // end namespace CS

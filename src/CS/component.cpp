#include "component.h"

namespace CS {

Component::Component(const QString& _title):
    SERIALIZER(title),
    title(_title)
{ }

Component::~Component() { }

} // end namespace CS

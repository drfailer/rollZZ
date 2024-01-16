#include "section.h"
#include "component.h"

namespace CS {

Section::Section(const QString& _title):
    SERIALIZER(title, components),
    title(_title)
{

}

Section::~Section() {
    for (Component* comp : components) {
        delete comp;
    }
}

void Section::addComponent(Component *component) {
    components.push_back(component);
}

void Section::removeComponent(Component* component) {
    if (components.removeOne(component)) {
        delete component;
    }
}

} // end namespace CS

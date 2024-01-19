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

void Section::move(bool up, Component *component) {
    int index = components.lastIndexOf(component);
    int newIndex = up ? index - 1 : index + 1;

    if (components.removeOne(component)) {
        components.insert(newIndex, component);
    }
}

} // end namespace CS

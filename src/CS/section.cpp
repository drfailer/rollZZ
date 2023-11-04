#include "section.h"
#include "component.h"

namespace CS {

Section::Section(const QString& title):
    title(title)
{

}

Section::~Section()
{
    for (auto comp : components) {
        delete comp;
    }
    components.clear();
}

void Section::addComponent(Component *component)
{
    components.push_back(component);
}

} // end namespace CS

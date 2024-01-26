#include "part.h"
#include "section.h"
#include <iostream>

namespace CS {

/******************************************************************************/
/*                          constructor & destructor                          */
/******************************************************************************/

Part::Part(const QString& _name):
    SERIALIZER(name, sections),
    name(_name)
{ }

Part::~Part() {
    for (CS::Section* section : sections) {
        delete section;
    }
}

/******************************************************************************/
/*                                 accessors                                  */
/******************************************************************************/

void Part::addSection(CS::Section* section) {
    sections.push_back(section);
}

void Part::removeSection(CS::Section* section) {
    if (sections.removeOne(section)) {
        delete section;
    } else {
        std::cout << "Error: this section deon't exists." << std::endl;
        std::cout << "Number of sections: " << sections.size() << std::endl;
    }
}

void Part::removeSection(int index) {
    removeSection(sections[index]);
}

} // end namespace CS

#include "gamecs/components/descriptor.h"
#include <QLabel>

namespace GameCS {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

Descriptor::Descriptor(CS::Descriptor *descriptor, QWidget *parent)
    : Tools::Component(descriptor->getTitle(), parent), descriptor(descriptor) {
    bodyAdd(new QLabel(descriptor->getDescription()));
    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; "
                  "border-radius: 5%; }"
                  "QFrame { background-color: #202020; }");
    // TODO: update on save
}

} // end namespace GameCS

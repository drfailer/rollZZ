#include "cseditor/components/descriptor.h"

namespace CSEditor {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

Descriptor::Descriptor(CS::Descriptor *descriptor, QWidget* parent):
    Component(descriptor->getTitle(), parent),
    descriptor(descriptor)
{
    switch (descriptor->getType()) {
    case CS::DescriptorTypes::ONELINE:
        bodyAdd(new QLineEdit());
        break;
    case CS::DescriptorTypes::LONG:
        bodyAdd(new QTextEdit());
        break;
    }

    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #202020; }"
                  );
    // TODO: update on save
}

} // end namespace CSEditor

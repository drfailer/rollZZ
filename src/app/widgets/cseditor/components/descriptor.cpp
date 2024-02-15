#include "cseditor/components/descriptor.h"
#include <QTextEdit>
#include <QLineEdit>

namespace CSEditor {

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

Descriptor::Descriptor(CS::Descriptor *descriptor, QWidget *parent)
    : Tools::Component(descriptor->getTitle(), parent), descriptor(descriptor) {
    switch (descriptor->getType()) {
    case CS::DescriptorTypes::ONELINE: {
        QLineEdit *contentEdit = new QLineEdit(this);
        contentEdit->setText(descriptor->getDescription());
        bodyAdd(contentEdit);
        connect(contentEdit, &QLineEdit::textChanged, this,
                [&](const QString& newText) {
                    this->descriptor->setDescription(newText);
                });
    } break;
    case CS::DescriptorTypes::LONG: {
        QTextEdit *contentEdit = new QTextEdit(this);
        contentEdit->setText(descriptor->getDescription());
        bodyAdd(contentEdit);
        connect(contentEdit, &QTextEdit::textChanged, this,
                [&, contentEdit]() {
                    this->descriptor->setDescription(contentEdit->document()->toPlainText());
                });
    } break;
    }

    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; "
                  "border-radius: 5%; }"
                  "QFrame { background-color: #202020; }");
    // TODO: update on save
}

} // end namespace CSEditor

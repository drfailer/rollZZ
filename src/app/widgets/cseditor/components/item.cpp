#include "cseditor/components/item.h"

namespace CSEditor {

Item::Item(CS::Item* item, bool useWeight, QWidget *parent):
    QWidget(parent),
    item(item),
    layout(this),
    nameEdit("name"),
    descriptionEdit("description"),
    removeBtn("X")
{
    layout.addWidget(&nameEdit);
    layout.addWidget(&descriptionEdit);
    layout.addWidget(&quantityEdit);

    if (useWeight) {
        layout.addWidget(&weightEdit);
    } else {
        weightEdit.hide();
    }
    layout.addWidget(&removeBtn);

    // connects
    connect(&removeBtn, &QPushButton::clicked, this, [&]{ emit remove(); });
    connect(&nameEdit, &QLineEdit::textChanged, this, [&](const QString& newText) {
                this->item->setName(newText);
            });
    connect(&descriptionEdit, &QLineEdit::textChanged, this, [&](const QString& newText) {
                this->item->setDescription(newText);
            });
    connect(&quantityEdit, &QSpinBox::valueChanged, this, [&](int newValue) {
                this->item->setQuantity(newValue);
            });
    connect(&weightEdit, &QSpinBox::valueChanged, this, [&](int newValue) {
                this->item->setWeight(newValue);
            });
}

} // end namespace CSEditor

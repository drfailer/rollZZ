#include "cseditor/components/item.h"

namespace CSEditor {

Item::Item(CS::Item* item, bool useWeight, QWidget *parent):
    QWidget(parent),
    item(item),
    layout(this)
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
}

void Item::connectWeightEdit(QObject* object, std::function<void(int)> function) {
    connect(&quantityEdit, &QSpinBox::valueChanged, object, function);
}

} // end namespace CSEditor

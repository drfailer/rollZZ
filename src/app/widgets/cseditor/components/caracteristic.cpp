#include "cseditor/components/caracteristic.h"
#include <QLabel>

namespace  CSEditor {

Caracteristic::Caracteristic(CS::Caracteristic* caracteristic, QWidget* parent):
    QWidget(parent),
    caracteristic(caracteristic),
    layout(this)
{
    bonusEdit.setMinimum(-100);
    bonusEdit.setValue(caracteristic->getBonus());
    layout.addWidget(&check);
    layout.addWidget(new QLabel(caracteristic->getName(), this));
    layout.addWidget(&bonusEdit);
    layout.addWidget(new QLabel("(" + caracteristic->getLinkedStatName() + ")", this));
    layout.setAlignment(Qt::AlignLeft);
    // TODO: compute the default bonus

    connect(&check, &QRadioButton::toggled, this, [&](bool checked) {
                this->caracteristic->setChecked(checked);
            });
    connect(&bonusEdit, &QSpinBox::valueChanged, this, [&](int newValue) {
                this->caracteristic->setBonus(newValue);
            });
}

} // end namespace CSEditor

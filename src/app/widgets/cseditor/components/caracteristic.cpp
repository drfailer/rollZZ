#include "cseditor/components/caracteristic.h"
#include <QLabel>

namespace  CSEditor {

Caracteristic::Caracteristic(CS::Caracteristic* caracteristic, QWidget* parent):
    QWidget(parent),
    caracteristic(caracteristic),
    layout(this)
{
    bonusEdit.setMinimum(0);
    layout.addWidget(new QLabel(caracteristic->getName()));
    layout.addWidget(&bonusEdit);
    // TODO: compute the default bonus
}

} // end namespace CSEditor

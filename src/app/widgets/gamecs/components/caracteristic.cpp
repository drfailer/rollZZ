#include "gamecs/components/caracteristic.h"
#include <QLabel>

namespace GameCS {

Caracteristic::Caracteristic(CS::Caracteristic *caracteristic, QWidget *parent):
    QWidget(parent),
    caracteristic(caracteristic),
    layout(this),
    rollBtn("roll")
{
    layout.addWidget(new QLabel((caracteristic->getChecked() ? "[X]" : "[ ]"), this));
    layout.addWidget(new QLabel(caracteristic->getName() + ": ", this));
    layout.addWidget(new QLabel(QString::number(caracteristic->getBonus()), this));
    layout.addWidget(new QLabel("(" + caracteristic->getLinkedStatName() + ")", this));
    layout.addWidget(&rollBtn);
    layout.setAlignment(Qt::AlignLeft);

    connect(&rollBtn, &QPushButton::clicked, this, [&]() {
        QString message = "rolled " + this->caracteristic->getName() + ": " +
                          QString::number(this->caracteristic->roll());
        emit rolled(message);
    });
}

} // end namespace GameCS

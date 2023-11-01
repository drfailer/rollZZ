#include "statcreationpopup.h"
#include <iostream>

StatCreationPopup::StatCreationPopup(QWidget *parent):
    QWidget(parent),
    layout(this),
    confirmBtn("add"),
    nameEdit("stat name"),
    valueEdit(0)
{
    layout.addWidget(&nameEdit);
    layout.addWidget(&valueEdit);
    layout.addWidget(&confirmBtn);

    connect(&confirmBtn, &QPushButton::clicked, this, [&]() {
        std::cout << "confirm" << std::endl;
        emit confirm();
    });
}

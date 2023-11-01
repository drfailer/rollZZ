#include "statcreationpopup.h"
#include <iostream>

StatCreationPopup::StatCreationPopup(QWidget *parent):
    QWidget(parent),
    mainLyt(this),
    title("STATISTIC"),
    nameEdit("stat name"),
    valueMaxEdit(0),
    confirmBtn("confirm"),
    cancelBtn("cancel"),
    btnLyt(this)
{
    mainLyt.addWidget(&title);
    mainLyt.addWidget(&nameEdit);
    mainLyt.addWidget(&valueMaxEdit);
    btnLyt.addWidget(&cancelBtn);
    btnLyt.addWidget(&confirmBtn);
    mainLyt.addLayout(&btnLyt);

    connect(&confirmBtn, &QPushButton::clicked, this, [&]() {
        emit confirm(true);
    });
    connect(&cancelBtn, &QPushButton::clicked, this, [&]() {
        emit confirm(false);
    });

    setFixedWidth(300);
    setFixedHeight(150);
    mainLyt.setAlignment(Qt::AlignTop);
}

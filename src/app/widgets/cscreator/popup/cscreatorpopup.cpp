#include "cscreatorpopup.h"

CSCreatorPopup::CSCreatorPopup(QString name):
    QWidget(nullptr),
    mainLyt(this),
    title(name),
    bodyLyt(this),
    btnLyt(this),
    confirmBtn("confirm"),
    cancelBtn("cancel")
{
    mainLyt.addWidget(&title);
    // body
    mainLyt.addLayout(&bodyLyt);
    // cancle / confirm
    btnLyt.addWidget(&cancelBtn);
    btnLyt.addWidget(&confirmBtn);
    mainLyt.addLayout(&btnLyt);

    // connect btns
    connect(&confirmBtn, &QPushButton::clicked, this, [&]() {
        emit confirm(true);
    });
    connect(&cancelBtn, &QPushButton::clicked, this, [&]() {
        emit confirm(false);
    });
    mainLyt.setAlignment(Qt::AlignTop);
    bodyLyt.setAlignment(Qt::AlignTop|Qt::AlignLeft);
}

void CSCreatorPopup::add(QWidget *wdgt)
{
    bodyLyt.addWidget(wdgt);
}
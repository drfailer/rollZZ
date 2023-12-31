#include "component.h"

namespace CSCreator {

Component::Component(const QString& title, QWidget *parent):
    QFrame(parent),
    mainLyt(this),
    title(title),
    removeBtn("X"),
    moveUpBtn("^"),
    moveDownBtn("v"),
    settingsBtn("O")
{
    headerLyt.addLayout(&titleLyt);
    headerLyt.addLayout(&btnsLyt);

    // title on the right
    titleLyt.addWidget(&this->title);

    // buttons on the left
    btnsLyt.addWidget(&settingsBtn);
    btnsLyt.addWidget(&removeBtn);
    btnsLyt.addWidget(&moveUpBtn);
    btnsLyt.addWidget(&moveDownBtn);

    // alignement
    btnsLyt.setAlignment(Qt::AlignRight);
    titleLyt.setAlignment(Qt::AlignLeft);
    // bodyLyt.setAlignment(Qt::AlignLeft);

    // add to the main layout
    mainLyt.addLayout(&headerLyt);
    mainLyt.addLayout(&bodyLyt);

    // connect buttons
    connect(&removeBtn, &QPushButton::clicked, this, [&]() { emit remove(); });
    connect(&moveUpBtn, &QPushButton::clicked, this, [&]() { emit moveUp(); });
    connect(&moveDownBtn, &QPushButton::clicked, this, [&]() { emit moveDown(); });
}

void Component::bodyAdd(QWidget *wgt)
{
    bodyLyt.addWidget(wgt);
}

void Component::bodyRemove(QWidget *wgt)
{
    bodyLyt.removeWidget(wgt);
}

void Component::bodyInsert(int index, QWidget *wgt)
{
    bodyLyt.insertWidget(index, wgt);
}

void Component::connectSettings()
{
    connect(&settingsBtn, &QPushButton::clicked, this, &Component::settingsPopup); // mother class
}

} // end namespace CSCreator

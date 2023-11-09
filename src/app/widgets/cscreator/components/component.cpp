#include "component.h"

namespace CSCreator {

Component::Component(const QString& title, QWidget *parent):
    QFrame(parent),
    mainLyt(this),
    headerLyt(this),
    bodyLyt(this),
    title(title),
    titleLyt(this),
    btnsLyt(this),
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

void Component::connectSettingFunction(Component *wgt, std::function<void()> function)
{
    connect(&settingsBtn, &QPushButton::clicked, wgt, function); // mother class
}

} // end namespace CSCreator

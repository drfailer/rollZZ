#include "cscreatorsection.h"

CSCreatorSection::CSCreatorSection(const QString& title, QWidget *parent):
    QWidget(parent),
    mainLyt(this),
    headerLyt(this),
    bodyLyt(this),
    title(title),
    titleLyt(this),
    btnsLyt(this),
    removeBtn("del"),
    settingsBtn("mod"),
    moveUpBtn("up"),
    moveDownBtn("dwn"),
    addElementBtn("new element")
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

    // body
    bodyLyt.addWidget(&addElementBtn);

    // alignement
    btnsLyt.setAlignment(Qt::AlignLeft);
    titleLyt.setAlignment(Qt::AlignRight);

    // add to the main layout
    mainLyt.addLayout(&headerLyt);
    mainLyt.addLayout(&bodyLyt);
}

void CSCreatorSection::add(QWidget *wgt)
{
    content.push_back(wgt);
    bodyLyt.addWidget(wgt);
}

void CSCreatorSection::move(Direction direction, QWidget *wgt)
{
    int index = content.indexOf(wgt);
    int newIndex = (direction == UP)? index - 1 : index + 1;

    bodyLyt.removeWidget(wgt);
    bodyLyt.insertWidget(newIndex, wgt);
}

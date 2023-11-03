#include "cscreator.h"
#include "cscreatorsection.h"
#include "popup/sectionpopup.h"
#include <iostream>

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
    setStyleSheet("QLabel { font-size: 18px; }"
                  "#QPushButton { font-size: 14px; }"
                  "#QWidget { background-color: #000000; }" // not working
                  );

    // buttons on the left
    btnsLyt.addWidget(&settingsBtn);
    btnsLyt.addWidget(&removeBtn);
    btnsLyt.addWidget(&moveUpBtn);
    btnsLyt.addWidget(&moveDownBtn);

    // body
    bodyLyt.addWidget(&addElementBtn);

    // alignement
    btnsLyt.setAlignment(Qt::AlignRight);
    titleLyt.setAlignment(Qt::AlignLeft);

    // add to the main layout
    mainLyt.addLayout(&headerLyt);
    mainLyt.addLayout(&bodyLyt);

    // connect buttons
    connect(&settingsBtn, &QPushButton::clicked, this, &CSCreatorSection::settingsPopup);
    connect(&removeBtn, &QPushButton::clicked, this, [&]() { std::cout << "todo" << std::endl; });
    connect(&moveUpBtn, &QPushButton::clicked, this, [&]() { std::cout << "todo" << std::endl; });
    connect(&moveDownBtn, &QPushButton::clicked, this, [&]() { std::cout << "todo" << std::endl; });
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

/******************************************************************************/
/* settings button                                                            */
/******************************************************************************/

void CSCreatorSection::settingsPopup()
{
    if (sectionPopup == nullptr) {
        sectionPopup = new SectionPopup(title.text());
    }
    sectionPopup->show();
    connect(sectionPopup, &SectionPopup::confirm, this, [&](bool confirm) {
        if (confirm) {
            title.setText(sectionPopup->getName());
        }
        // remove the popup window
        delete sectionPopup;
        sectionPopup = nullptr;
    });
}

#include "cscreator.h"
#include "cscreatorsection.h"
#include "popup/sectionpopup.h"
#include <QPalette>
#include <iostream>

CSCreatorSection::CSCreatorSection(const QString& title, QWidget *parent):
    QFrame(parent),
    mainLyt(this),
    headerLyt(this),
    bodyLyt(this),
    title(title),
    titleLyt(this),
    btnsLyt(this),
    removeBtn("X"),
    settingsBtn("O"),
    moveUpBtn("^"),
    moveDownBtn("v"),
    addElementBtn(this)
{
    headerLyt.addLayout(&titleLyt);
    headerLyt.addLayout(&btnsLyt);

    // title on the right
    titleLyt.addWidget(&this->title);
    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #222222; }"
                  );

    // buttons on the left
    btnsLyt.addWidget(&settingsBtn);
    btnsLyt.addWidget(&removeBtn);
    btnsLyt.addWidget(&moveUpBtn);
    btnsLyt.addWidget(&moveDownBtn);

    // body
    bodyLyt.addWidget(&addElementBtn);
    addElementBtn.addItem("+", None);
    addElementBtn.addItem("basic stat", BasicStat);
    addElementBtn.addItem("bonus stat", BonusStat);
    addElementBtn.addItem("list stat", ListStat);
    addElementBtn.addItem("descriptor", Descriptor);
    addElementBtn.addItem("attacks & spells", Attacks);
    addElementBtn.setFixedWidth(43);
    bodyLyt.setAlignment(Qt::AlignLeft);

    // alignement
    btnsLyt.setAlignment(Qt::AlignRight);
    titleLyt.setAlignment(Qt::AlignLeft);

    // add to the main layout
    mainLyt.addLayout(&headerLyt);
    mainLyt.addLayout(&bodyLyt);

    // connect buttons
    connect(&settingsBtn, &QPushButton::clicked, this, &CSCreatorSection::settingsPopup);
    connect(&removeBtn, &QPushButton::clicked, this, [&]() { emit remove(); });
    connect(&moveUpBtn, &QPushButton::clicked, this, [&]() { emit moveUp(); });
    connect(&moveDownBtn, &QPushButton::clicked, this, [&]() { emit moveDown(); });
    connect(&addElementBtn, &QComboBox::activated, this, &CSCreatorSection::addElement);
}

CSCreatorSection::~CSCreatorSection()
{
    for (auto wgt : content) {
        delete wgt;
    }
}

void CSCreatorSection::add(QWidget *wgt)
{
    content.push_back(wgt);
    bodyLyt.addWidget(wgt);
}

void CSCreatorSection::move(bool up, QWidget *wgt)
{
    int index = content.indexOf(wgt);
    int newIndex = up ? index - 1 : index + 1;

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

void CSCreatorSection::addElement(int element)
{
    switch (element) {
    case None:
        break;
    case BasicStat:
        std::cout << "add basic stat" << std::endl;
        break;
    case BonusStat:
        std::cout << "add bonus stat" << std::endl;
        break;
    case ListStat:
        std::cout << "add list stat" << std::endl;
        break;
    case Descriptor:
        std::cout << "add descriptor" << std::endl;
        break;
    case Attacks:
        std::cout << "add attacks & spells" << std::endl;
        break;
    }
    addElementBtn.setCurrentIndex(None);
}

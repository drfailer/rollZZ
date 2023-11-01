#include "cscreator.h"
#include <iostream>

CSCreator::CSCreator(QWidget *parent):
    QWidget(parent),
    statCreationPopup(nullptr)
{

}

CSCreator::~CSCreator()
{
    for (auto wgt : statList->children()) {
        delete wgt;
    }
}

void CSCreator::config(QPushButton *newStat, QGridLayout *statList)
{
    this->newStat = newStat;
    this->statList = statList;

    // change spacing of the grid layout for stats
    this->statList->setHorizontalSpacing(10);
    this->statList->setVerticalSpacing(10);

    // TODO: popup window
    connect(newStat, &QPushButton::clicked, this, &CSCreator::addStatPopup);
}

void CSCreator::addStatPopup()
{
    if (statCreationPopup == nullptr) {
        statCreationPopup = new StatCreationPopup(nullptr);
    }
    statCreationPopup->setFixedWidth(200);
    statCreationPopup->setFixedHeight(100);
    statCreationPopup->show();
    connect(statCreationPopup, &StatCreationPopup::confirm, this, &CSCreator::addStat);
}

void CSCreator::addStat()
{
    QPushButton *button = new QPushButton(statCreationPopup->getName());

    // add the button to the grid
    this->statList->addWidget(button, index/3, index%3);
    index++;
    // remove the popup window
    delete statCreationPopup;
    statCreationPopup = nullptr;
}

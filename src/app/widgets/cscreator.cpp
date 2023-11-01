#include "cscreator.h"

CSCreator::CSCreator(QWidget *parent)
    : QWidget{parent}
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
    connect(newStat, &QPushButton::clicked, this, [&](){
        this->statList->addWidget(new QPushButton("Button Text"), index/3, index%3);
        index++;
    });
}

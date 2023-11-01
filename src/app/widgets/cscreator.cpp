#include "cscreator.h"
#include "popup/statcreationpopup.h"
#include <iostream>

CSCreator::CSCreator(CSCreatorConfig config, QWidget *parent):
    QWidget(parent),
    addCategoryBtn(config.addCategoryBtn),
    addDescritorBtn(config.addDescritorBtn),
    addStatBtn(config.addStatBtn),
    addEquipmentBtn(config.addEquipmentBtn),
    addMoneyBtn(config.addMoneyBtn),
    sheetBase(config.sheetBase)
{
    sheetBase->setHorizontalSpacing(10);
    sheetBase->setVerticalSpacing(10);

    // connect for bnts
    connect(addStatBtn, &QPushButton::clicked, this, &CSCreator::addStatPopup);
}

CSCreator::~CSCreator()
{
    for (auto wgt : sheetBase->children()) {
        delete wgt;
    }
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
    // TODO: create a custom widget for this
    QPushButton *button = new QPushButton(statCreationPopup->getName());

    // TODO: find a way to make the stat modifiable

    // add the button to the grid
    sheetBase->addWidget(button, index/3, index%3);
    index++;
    // remove the popup window
    delete statCreationPopup;
    statCreationPopup = nullptr;
}

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
    sheetContent(config.sheetContent)
{
    sheetContent->setSpacing(10);
    sheetContent->setAlignment(Qt::AlignLeft|Qt::AlignTop);

    // connect for bnts
    connect(addStatBtn, &QPushButton::clicked, this, &CSCreator::addStatPopup);
}

CSCreator::~CSCreator()
{
    for (auto wgt : sheetContent->children()) {
        delete wgt;
    }
}

void CSCreator::addStatPopup()
{
    if (statCreationPopup == nullptr) {
        statCreationPopup = new StatCreationPopup(nullptr);
    }
    statCreationPopup->show();
    connect(statCreationPopup, &StatCreationPopup::confirm, this, &CSCreator::addStat);
}

void CSCreator::addStat(bool add)
{
    if (add) {
        // TODO: create a custom widget for this
        QPushButton *button = new QPushButton(statCreationPopup->getName());
        // add the button to the grid
        sheetContent->addWidget(button);
        index++;
    }
    // remove the popup window
    delete statCreationPopup;
    statCreationPopup = nullptr;
}

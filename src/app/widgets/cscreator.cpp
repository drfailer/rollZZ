#include "cscreator.h"
#include "popup/statcreationpopup.h"
#include <iostream>

CSCreator::CSCreator(CSCreatorConfig config, QWidget *parent):
    QWidget(parent),
    addCategoryBtn(config.addCategoryBtn),
    addDescritorBtn(config.addDescritorBtn),
    addStatBtn(config.addStatBtn),
    addEquipmentBtn(config.addEquipmentBtn),
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

/******************************************************************************/
/* add Category                                                               */
/******************************************************************************/

void CSCreator::addCategoryPopup()
{
    // if (statCreationPopup == nullptr) {
        // statCreationPopup = new StatCreationPopup(nullptr);
    // }
    // statCreationPopup->show();
    // connect(statCreationPopup, &StatCreationPopup::confirm, this, &CSCreator::addStat);
}

void CSCreator::addCategory(bool add)
{
    // if (add) {
        // // TODO: create a custom widget for this
        // QPushButton *button = new QPushButton(statCreationPopup->getName());
        // // add the button to the grid
        // sheetContent->addWidget(button);
        // index++;
    // }
    // // remove the popup window
    // delete statCreationPopup;
    // statCreationPopup = nullptr;
}

/******************************************************************************/
/* add descriptor                                                             */
/******************************************************************************/

void CSCreator::addDescriptorPopup()
{
    // if (statCreationPopup == nullptr) {
        // statCreationPopup = new StatCreationPopup(nullptr);
    // }
    // statCreationPopup->show();
    // connect(statCreationPopup, &StatCreationPopup::confirm, this, &CSCreator::addStat);
}

void CSCreator::addDescriptor(bool add)
{
    // if (add) {
        // // TODO: create a custom widget for this
        // QPushButton *button = new QPushButton(statCreationPopup->getName());
        // // add the button to the grid
        // sheetContent->addWidget(button);
        // index++;
    // }
    // // remove the popup window
    // delete statCreationPopup;
    // statCreationPopup = nullptr;
}

/******************************************************************************/
/* add statistic                                                              */
/******************************************************************************/

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

/******************************************************************************/
/* add equipment                                                              */
/******************************************************************************/

void CSCreator::addEquipmentPopup()
{
    // if (statCreationPopup == nullptr) {
        // statCreationPopup = new StatCreationPopup(nullptr);
    // }
    // statCreationPopup->show();
    // connect(statCreationPopup, &StatCreationPopup::confirm, this, &CSCreator::addStat);
}

void CSCreator::addEquipment(bool add)
{
    // if (add) {
        // // TODO: create a custom widget for this
        // QPushButton *button = new QPushButton(statCreationPopup->getName());
        // // add the button to the grid
        // sheetContent->addWidget(button);
        // index++;
    // }
    // // remove the popup window
    // delete statCreationPopup;
    // statCreationPopup = nullptr;
}

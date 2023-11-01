#include "cscreator.h"
#include "popup/categorycreationpopup.h"
#include "popup/descriptorcreationpopup.h"
#include "popup/statcreationpopup.h"
#include "popup/equipmentcreationpopup.h"
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
    connect(addCategoryBtn, &QPushButton::clicked, this, &CSCreator::addCategoryPopup);
    connect(addDescritorBtn, &QPushButton::clicked, this, &CSCreator::addDescriptorPopup);
    connect(addStatBtn, &QPushButton::clicked, this, &CSCreator::addStatPopup);
    connect(addEquipmentBtn, &QPushButton::clicked, this, &CSCreator::addEquipmentPopup);
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
    if (categoryCreationPopup == nullptr) {
        categoryCreationPopup = new CategoryCreationPopup();
    }
    categoryCreationPopup->show();
    connect(categoryCreationPopup, &CategoryCreationPopup::confirm, this, &CSCreator::addCategory);
}

void CSCreator::addCategory(bool add)
{
    if (add) {
        // TODO: create a custom widget for this
        QPushButton *button = new QPushButton(categoryCreationPopup->getName());
        // add the button to the grid
        sheetContent->addWidget(button);
        index++;
    }
    // remove the popup window
    delete categoryCreationPopup;
    categoryCreationPopup = nullptr;
}

/******************************************************************************/
/* add descriptor                                                             */
/******************************************************************************/

void CSCreator::addDescriptorPopup()
{
    if (descriptorCreationPopup == nullptr) {
        descriptorCreationPopup = new DescriptorCreationPopup();
    }
    descriptorCreationPopup->show();
    connect(descriptorCreationPopup, &DescriptorCreationPopup::confirm, this, &CSCreator::addDescriptor);
}

void CSCreator::addDescriptor(bool add)
{
    if (add) {
        // TODO: create a custom widget for this
        QPushButton *button = new QPushButton(descriptorCreationPopup->getName());
        // add the button to the grid
        sheetContent->addWidget(button);
        index++;
    }
    // remove the popup window
    delete descriptorCreationPopup;
    descriptorCreationPopup = nullptr;
}

/******************************************************************************/
/* add statistic                                                              */
/******************************************************************************/

void CSCreator::addStatPopup()
{
    if (statCreationPopup == nullptr) {
        statCreationPopup = new StatCreationPopup();
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
    if (equipmentCreationPopup == nullptr) {
        equipmentCreationPopup = new EquipmentCreationPopup();
    }
    equipmentCreationPopup->show();
    connect(equipmentCreationPopup, &EquipmentCreationPopup::confirm, this, &CSCreator::addEquipment);
}

void CSCreator::addEquipment(bool add)
{
    if (add) {
        // TODO: create a custom widget for this
        QPushButton *button = new QPushButton(equipmentCreationPopup->getName());
        // add the button to the grid
        sheetContent->addWidget(button);
        index++;
    }
    // remove the popup window
    delete equipmentCreationPopup;
    equipmentCreationPopup = nullptr;
}

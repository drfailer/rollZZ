#include "cscreator.h"
#include <QTabWidget>
#include "popup/categorycreationpopup.h"
#include "popup/descriptorcreationpopup.h"
#include "popup/tabpopup.h"
#include "popup/statcreationpopup.h"
#include "popup/equipmentcreationpopup.h"
#include <iostream>
#define ADD_FN(id) [&](bool add) { id(add); }

CSCreator::CSCreator(CSCreatorConfig config, QWidget *parent):
    QWidget(parent),
    contentWgt(config.contentWgt),
    contentLyt(new QVBoxLayout(this)),
    tabWgt(new QTabWidget(this)),
    newTabBtn(config.newTabBtn),
    saveBtn(config.saveBtn),
    importBtn(config.importBtn)
{
    // add the tabWgt in the page
    contentWgt->setLayout(contentLyt);
    contentLyt->addWidget(tabWgt);
    tabWgt->setMovable(true);
    tabWgt->setTabPosition(QTabWidget::South);

    // add the first tab
    tabWgt->addTab(createTab(), "main");

    // the other buttons
    // connect(newTabBtn, &QPushButton::clicked, this, [&]() { addElementPopup(newTabPopup, ADD_FN(addTab)); });
    connect(newTabBtn, &QPushButton::clicked, this, &CSCreator::addTabPopup);
    connect(tabWgt, &QTabWidget::tabBarDoubleClicked, this, &CSCreator::renameTabPopup);
    connect(saveBtn, &QPushButton::clicked, this, [&]() { std::cout << "todo" << std::endl; });
    connect(importBtn, &QPushButton::clicked, this, [&]() { std::cout << "todo" << std::endl; });

    // connect for bnts
    // connect(addCategoryBtn, &QPushButton::clicked, this, &CSCreator::addCategoryPopup);
    // connect(addDescritorBtn, &QPushButton::clicked, this, &CSCreator::addDescriptorPopup);
    // connect(addStatBtn, &QPushButton::clicked, this, &CSCreator::addStatPopup);
    // connect(addEquipmentBtn, &QPushButton::clicked, this, &CSCreator::addEquipmentPopup);
}

CSCreator::~CSCreator()
{
    // I don't know if it works like this
    for (auto wgt : tabWgt->children()) {
        delete wgt;
    }
    delete contentLyt;
    delete tabWgt;
}

/******************************************************************************/
/* Tabs                                                                       */
/******************************************************************************/

QWidget* CSCreator::createTab()
{
    QWidget *newTabWgt = new QWidget(tabWgt);
    QVBoxLayout *newTabLyt = new QVBoxLayout(newTabWgt);
    QPushButton *newSectionBtn = new QPushButton("new section");

    newTabLyt->addWidget(newSectionBtn);
    newTabWgt->setLayout(newTabLyt);
    newTabLyt->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    connect(newSectionBtn, &QPushButton::clicked, this, [&]() { std::cout << "todo" << std::endl; });
    tabs.push_back(newTabWgt);
    return newTabWgt;
}

void CSCreator::addTabPopup()
{
    if (tabPopup == nullptr) {
        tabPopup = new TabPopup("NEW TAB");
    }
    tabPopup->show();
    connect(tabPopup, &TabPopup::confirm, this, &CSCreator::addTab);
}

void CSCreator::addTab(bool add)
{
    if (add) {
        tabWgt->addTab(createTab(), tabPopup->getName());
    }
    // remove the popup window
    delete tabPopup;
    tabPopup = nullptr;
}

void CSCreator::renameTabPopup(int index)
{
    if (tabPopup == nullptr) {
        tabPopup = new TabPopup("RENAME TAB", tabWgt->tabText(index));
    }
    tabPopup->show();
    connect(tabPopup, &TabPopup::confirm, this, [&, index](bool rename) { renameTab(index, rename); });
}

void CSCreator::renameTab(int index, bool rename)
{
    if (rename) {
        tabWgt->setTabText(index, tabPopup->getName());
    }
    // remove the popup window
    delete tabPopup;
    tabPopup = nullptr;
}

/******************************************************************************/
/* add Category                                                               */
/******************************************************************************/

// void CSCreator::addCategoryPopup()
// {
    // if (categoryCreationPopup == nullptr) {
        // categoryCreationPopup = new CategoryCreationPopup();
    // }
    // categoryCreationPopup->show();
    // connect(categoryCreationPopup, &CategoryCreationPopup::confirm, this, &CSCreator::addCategory);
// }

// void CSCreator::addCategory(bool add)
// {
    // if (add) {
        // // TODO: create a custom widget for this
        // QPushButton *button = new QPushButton(categoryCreationPopup->getName());
        // // add the button to the grid
        // sheetContent->addWidget(button);
        // index++;
    // }
    // // remove the popup window
    // delete categoryCreationPopup;
    // categoryCreationPopup = nullptr;
// }

/******************************************************************************/
/* add descriptor                                                             */
/******************************************************************************/

// void CSCreator::addDescriptorPopup()
// {
    // if (descriptorCreationPopup == nullptr) {
        // descriptorCreationPopup = new DescriptorCreationPopup();
    // }
    // descriptorCreationPopup->show();
    // connect(descriptorCreationPopup, &DescriptorCreationPopup::confirm, this, &CSCreator::addDescriptor);
// }

// void CSCreator::addDescriptor(bool add)
// {
    // if (add) {
        // // TODO: create a custom widget for this
        // QPushButton *button = new QPushButton(descriptorCreationPopup->getName());
        // // add the button to the grid
        // sheetContent->addWidget(button);
        // index++;
    // }
    // // remove the popup window
    // delete descriptorCreationPopup;
    // descriptorCreationPopup = nullptr;
// }

/******************************************************************************/
/* add statistic                                                              */
/******************************************************************************/

// void CSCreator::addStatPopup()
// {
    // if (statCreationPopup == nullptr) {
        // statCreationPopup = new StatCreationPopup();
    // }
    // statCreationPopup->show();
    // connect(statCreationPopup, &StatCreationPopup::confirm, this, &CSCreator::addStat);
// }

// void CSCreator::addStat(bool add)
// {
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
// }

/******************************************************************************/
/* add equipment                                                              */
/******************************************************************************/

// void CSCreator::addEquipmentPopup()
// {
    // if (equipmentCreationPopup == nullptr) {
        // equipmentCreationPopup = new EquipmentCreationPopup();
    // }
    // equipmentCreationPopup->show();
    // connect(equipmentCreationPopup, &EquipmentCreationPopup::confirm, this, &CSCreator::addEquipment);
// }

// void CSCreator::addEquipment(bool add)
// {
    // if (add) {
        // // TODO: create a custom widget for this
        // QPushButton *button = new QPushButton(equipmentCreationPopup->getName());
        // // add the button to the grid
        // sheetContent->addWidget(button);
        // index++;
    // }
    // // remove the popup window
    // delete equipmentCreationPopup;
    // equipmentCreationPopup = nullptr;
// }

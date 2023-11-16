#include "cscreator.h"
#include "components/section.h"
#include "popup/sectionpopup.h"
#include "popup/descriptorpopup.h"
#include "popup/tabpopup.h"
#include "popup/basicstatpopup.h"
#include "popup/equipmentpopup.h"
#include <QTabWidget>
#include <iostream>
#define ADD_FN(id) [&](bool add) { id(add); }


namespace CSCreator {

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
    connect(newTabBtn, &QPushButton::clicked, this, &CSCreator::addTabPopup);
    connect(tabWgt, &QTabWidget::tabBarDoubleClicked, this, &CSCreator::renameTabPopup);
    connect(saveBtn, &QPushButton::clicked, this, [&]() { std::cout << "todo" << std::endl; });
    connect(importBtn, &QPushButton::clicked, this, [&]() { std::cout << "todo" << std::endl; });
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

void CSCreator::move(bool up, QWidget *wgt)
{
    int index = currentTabLyt()->indexOf(wgt);
    int newIndex = up ? index - 1 : index + 1;

    if (newIndex >= 0 && newIndex < currentTabLyt()->count() - 1) {
        currentTabLyt()->removeWidget(wgt);
        currentTabLyt()->insertWidget(newIndex, wgt);
    }
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
    newTabLyt->setAlignment(Qt::AlignTop);
    connect(newSectionBtn, &QPushButton::clicked, this, &CSCreator::addSectionPopup);
    tabs.push_back(newTabWgt);
    return newTabWgt;
}

void CSCreator::addTabPopup()
{
    if (tabPopup == nullptr) {
        tabPopup = new TabPopup("NEW TAB");
    }
    tabPopup->show();
    connect(tabPopup, &TabPopup::confirm, this, [&](bool add) {
        if (add) {
            tabWgt->addTab(createTab(), tabPopup->getName());
        }
        // remove the popup window
        delete tabPopup;
        tabPopup = nullptr;
    });
}

void CSCreator::renameTabPopup(int index)
{
    if (tabPopup == nullptr) {
        tabPopup = new TabPopup("RENAME TAB", tabWgt->tabText(index));
    }
    tabPopup->show();
    connect(tabPopup, &TabPopup::confirm, this, [&, index](bool rename) {
        if (rename) {
            tabWgt->setTabText(index, tabPopup->getName());
        }
        // remove the popup window
        delete tabPopup;
        tabPopup = nullptr;
    });
}

/******************************************************************************/
/* add Category                                                               */
/******************************************************************************/

void CSCreator::addSectionPopup()
{
    if (sectionPopup == nullptr) {
        sectionPopup = new SectionPopup();
    }
    sectionPopup->show();
    connect(sectionPopup, &SectionPopup::confirm, this, [&](bool add) {
        if (add) {
            // TODO: create a custom widget for this
            Section *newSection = new Section(sectionPopup->getName(), this);
            currentTabLyt()->insertWidget(currentTabLyt()->count() - 1, newSection);
            index++;
            // connections
            connect(newSection, &Section::remove, this, [&, wgt = newSection]() { currentTabLyt()->removeWidget(wgt); delete wgt; });
            connect(newSection, &Section::moveUp, this, [&, wgt = newSection]() { move(true, wgt); });
            connect(newSection, &Section::moveDown, this, [&, wgt = newSection]() { move(false, wgt); });
        }
        // remove the popup window
        delete sectionPopup;
        sectionPopup = nullptr;
    });
}

} // end namespace CSCreator

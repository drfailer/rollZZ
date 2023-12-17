#include "cscreator.h"
#include "components/section.h"
#include "popup/sectionpopup.h"
#include "popup/tabpopup.h"
#include "section.h"
#include <CS/part.h>
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
    parts.insert(newTabWgt, new CS::Part());
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
            QWidget* newTab = createTab();
            tabWgt->addTab(newTab, tabPopup->getName());
            parts[newTab]->setName(tabPopup->getName());
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
            parts[tabWgt->widget(index)]->setName(tabPopup->getName());
        }
        // remove the popup window
        delete tabPopup;
        tabPopup = nullptr;
    });
}

// TODO: removeTab

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
            CS::Section* newSection = new CS::Section(sectionPopup->getName());
            Section *newSectionWgt = new Section(newSection, sectionPopup->getName(), this);
            currentTabLyt()->insertWidget(currentTabLyt()->count() - 1, newSectionWgt);
            parts[tabWgt->widget(tabWgt->currentIndex())]->addSection(newSection);
            index++;
            // connections
            connect(newSectionWgt, &Section::remove, this, [&, newSection, wgt = newSectionWgt]() {
                        parts[tabWgt->widget(tabWgt->currentIndex())]->removeSection(newSection);
                        currentTabLyt()->removeWidget(wgt);
                        delete wgt;
                    });
            connect(newSectionWgt, &Section::moveUp, this, [&, wgt = newSectionWgt]() {
                        move(true, wgt);
                    });
            connect(newSectionWgt, &Section::moveDown, this, [&, wgt = newSectionWgt]() {
                        move(false, wgt);
                    });
        }
        // remove the popup window
        delete sectionPopup;
        sectionPopup = nullptr;
    });
}

} // end namespace CSCreator

#include "cscreator.h"
#include "bonusstat.h"
#include "component.h"
#include "components/section.h"
#include "popup/tabpopup.h"
#include "section.h"
#include <CS/part.h>
#include <QTabWidget>
#include <QScrollArea>
#include "cscreator/components/section.h"
#include "cscreator/components/basicstat.h"
#include "cscreator/components/bonusstat.h"
#include "cscreator/components/attacks.h"
#include "cscreator/components/liststat.h"
#include "cscreator/components/descriptor.h"
#include "cscreator/components/equipment.h"
#include "cscreator/components/part.h"
#include <iostream>
#define ADD_FN(id) [&](bool add) { id(add); }


namespace CSCreator {

CSCreator::CSCreator(CSCreatorConfig config, CS::CS *CSTree, QWidget *parent):
    QWidget(parent),
    contentWgt(config.contentWgt),
    contentLyt(new QVBoxLayout(this)),
    tabWgt(new QTabWidget(this)),
    newTabBtn(config.newTabBtn),
    saveBtn(config.saveBtn),
    importBtn(config.importBtn),
    CSTree(CSTree)
{
    // add the tabWgt in the page
    contentWgt->setLayout(contentLyt);
    contentLyt->addWidget(tabWgt);
    tabWgt->setMovable(true);
    tabWgt->setTabPosition(QTabWidget::South);

    // add the first tab
    QWidget *defaultTabWgt = createTab("main");
    QScrollArea *defaultScrollArea = createScrollArea();
    defaultScrollArea->setWidget(defaultTabWgt);
    tabWgt->addTab(defaultScrollArea, "main");

    // the other buttons
    connect(newTabBtn, &QPushButton::clicked, this, &CSCreator::addTabPopup);
    connect(tabWgt, &QTabWidget::tabBarDoubleClicked, this, &CSCreator::renameTabPopup);
    connect(saveBtn, &QPushButton::clicked, this, [&]() {
                // TODO: create a popup to ask filename
                this->CSTree->serializeFile("test.txt");
            });
    connect(importBtn, &QPushButton::clicked, this, [&, CSTree]() {
                // TODO: create a popup to ask filename
                CSTree->load("test.txt");
                reload();
            });
}

CSCreator::~CSCreator() {
}

/******************************************************************************/
/* Tabs                                                                       */
/******************************************************************************/

QWidget* CSCreator::createTab(const QString& name) {
    CS::Part *newPart = new CS::Part(name);
    Part* newPartWgt = new Part(newPart, tabWgt);

    CSTree->addPart(newPart);
    return newPartWgt;
}

void CSCreator::addTabPopup() {
    if (tabPopup == nullptr) {
        tabPopup = new TabPopup("NEW TAB");
    }
    tabPopup->show();
    connect(tabPopup, &TabPopup::confirm, this, [&](bool add) {
        if (add) {
            QWidget* newTab = createTab(tabPopup->getName());
            QScrollArea *scrollArea = createScrollArea();

            scrollArea->setWidget(newTab);
            tabWgt->addTab(scrollArea, tabPopup->getName());
        }
        // remove the popup window
        delete tabPopup;
        tabPopup = nullptr;
    });
}

void CSCreator::renameTabPopup(int index) {
    if (tabPopup == nullptr) {
        tabPopup = new TabPopup("RENAME TAB", tabWgt->tabText(index));
    }
    tabPopup->show();
    connect(tabPopup, &TabPopup::confirm, this, [&, index](bool rename) {
        if (rename) {
            tabWgt->setTabText(index, tabPopup->getName());
            getPart(index)->setName(tabPopup->getName());
        }
        // remove the popup window
        delete tabPopup;
        tabPopup = nullptr;
    });
}

// TODO: removeTab

/******************************************************************************/
/*                                   reload                                   */
/******************************************************************************/

void CSCreator::reload() {
    clearTabs();

    // update the widgets
    for (CS::Part* part : CSTree->getParts()) {
        reloadPart(part);
    }
}

void CSCreator::reloadPart(CS::Part *part) {
    QWidget *newTabWgt = createTab(part->getName());
    QVBoxLayout *layout = dynamic_cast<QVBoxLayout*>(newTabWgt->layout());
    QScrollArea *scrollArea = createScrollArea();

    // adding widgets
    for (CS::Section *section : part->getSections()) {
        /* Section *newSectionWgt = createSection(section); */
        /* int count = layout->count(); */

        /* for (CS::Component *component : section->getComponents()) { */
        /*     newSectionWgt->add(createComponent(component), component); */
        /* } */
        /* layout->insertWidget(count - 1, newSectionWgt); */
    }

    scrollArea->setWidget(newTabWgt);
    tabWgt->addTab(scrollArea, part->getName());
}

/******************************************************************************/
/*                              create elements                               */
/******************************************************************************/

Component *CSCreator::createComponent(CS::Component *component) {
    if (CS::BonusStat* bonusStat = dynamic_cast<CS::BonusStat*>(component)) {
        return new BonusStat(bonusStat, this);
    } else if (CS::BasicStat* basicStat = dynamic_cast<CS::BasicStat*>(component)) {
        return new BasicStat(basicStat, this);
    } else if (CS::ListStat* listStat = dynamic_cast<CS::ListStat*>(component)) {
        return new ListStat(listStat, this);
    } else if (CS::Descriptor* descriptor = dynamic_cast<CS::Descriptor*>(component)) {
        return new Descriptor(descriptor, this);
    } else if (CS::Equipment* equipment = dynamic_cast<CS::Equipment*>(component)) {
        return new Equipment(equipment, this);
    } else if (CS::Attacks* attacks = dynamic_cast<CS::Attacks*>(component)) {
        return new Attacks(attacks, this);
    }
    return nullptr;
}

void CSCreator::clearTabs() {
    // clear tabs
    for (int i = 0; i < tabWgt->count(); ++i) {
        QWidget *wgt = tabWgt->widget(i);
        tabWgt->removeTab(i);
        delete wgt;
    }
}

Part *CSCreator::getPart(int index) {
    QScrollArea *scrollArea =
        dynamic_cast<QScrollArea *>(tabWgt->widget(index));
    return dynamic_cast<Part *>(scrollArea->widget());
}

QScrollArea *CSCreator::createScrollArea() {
    QScrollArea *scrollArea = new QScrollArea(this);

    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setWidgetResizable(true);
    return scrollArea;
}
} // end namespace CSCreator

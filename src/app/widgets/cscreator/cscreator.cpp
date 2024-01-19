#include "cscreator.h"
#include "fileselectorpopup.h"
#include "popup/tabpopup.h"
#include <CS/part.h>
#include <QTabWidget>
#include <QScrollArea>
#include "cscreator/components/part.h"
#include <iostream>


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
    connect(saveBtn, &QPushButton::clicked, this, &CSCreator::saveTemplateFile);
    connect(importBtn, &QPushButton::clicked, this, &CSCreator::loadTemplateFile);
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
        Part* newPartWgt = new Part(part, tabWgt);
        QScrollArea *scrollArea = createScrollArea();

        scrollArea->setWidget(newPartWgt);
        tabWgt->addTab(scrollArea, part->getName());
    }
}

/******************************************************************************/
/*                             utility functions                              */
/******************************************************************************/

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

/******************************************************************************/
/*                            load and save cstree                            */
/******************************************************************************/

void CSCreator::loadTemplateFile() {
    if (fileSelectorPopup == nullptr) {
        fileSelectorPopup = new FileSelectorPopup("Select a file to load");
        fileSelectorPopup->show();

        connect(fileSelectorPopup, &CSCreatorPopup::confirm, [&](bool confirm) {
                if (confirm) {
                    CSTree->load(fileSelectorPopup->getFile());
                    reload();
                }
                delete fileSelectorPopup;
                fileSelectorPopup = nullptr;
        });
    }
}

void CSCreator::saveTemplateFile() {
    if (fileSelectorPopup == nullptr) {
        fileSelectorPopup = new FileSelectorPopup("Select a file to load");
        fileSelectorPopup->show();

        connect(fileSelectorPopup, &CSCreatorPopup::confirm, [&](bool confirm) {
                if (confirm) {
                    std::cout << "save in: " << fileSelectorPopup->getFile().toStdString() <<
                    std::endl;
                    CSTree->save(fileSelectorPopup->getFile());
                }
                delete fileSelectorPopup;
                fileSelectorPopup = nullptr;
        });
    }
}

} // end namespace CSCreator

#include "gamecs.h"
#include "gamecs/components/section.h"
#include "CS/section.h"
#include <CS/part.h>
#include <QTabWidget>
#include <QScrollArea>
#include <iostream>

namespace GameCS {

// TODO: get the title in the cnfiguration and change it (put the name of the
// character).

GameCS::GameCS(const QString& csFile):
    QWidget(nullptr),
    contentLyt(new QVBoxLayout(this)),
    tabWgt(new QTabWidget(this)),
    saveBtn(new QPushButton("save", this)),
    csFile(csFile)
{
    std::cout << csFile.toStdString() << std::endl;
    CSTree.load(csFile);

    // add the tabWgt in the page
    setLayout(contentLyt);
    contentLyt->addWidget(tabWgt);
    contentLyt->addWidget(saveBtn);
    tabWgt->setMovable(false);
    tabWgt->setTabPosition(QTabWidget::South);

    // add parts
    for (CS::Part *part : CSTree.getParts()) {
        tabWgt->addTab(createTab(part), part->getName());
    }

    setContentsMargins(0, 0, 0, 0);
    contentLyt->setContentsMargins(0, 0, 0, 0);
    setStyleSheet("background-color: rgb(27, 27, 27); color: rgb(242, 242, 242);");

    // connect save button
    connect(saveBtn, &QPushButton::clicked, this, [&]() {
        this->CSTree.save(this->csFile);
    });
}

GameCS::~GameCS() {
    // remove all widgets (the page is reloaded each time it's open)
    delete contentLyt;
    contentLyt = nullptr;
}

QWidget* GameCS::createTab(CS::Part* part) {
    QWidget *newTabWgt = new QWidget(tabWgt);
    QVBoxLayout *newTabLyt = new QVBoxLayout(newTabWgt);
    QScrollArea *scrollArea = new QScrollArea(this);

    newTabLyt->setContentsMargins(0, 0, 0, 0);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setWidgetResizable(true);

    for (CS::Section* section : part->getSections()) {
        newTabLyt->addWidget(new Section(section, newTabWgt));
    }

    newTabWgt->setLayout(newTabLyt);
    newTabLyt->setAlignment(Qt::AlignTop);
    scrollArea->setWidget(newTabWgt);
    return scrollArea;
}

} // end namespace GameCS

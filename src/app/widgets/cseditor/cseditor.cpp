#include "cseditor.h"
#include "cseditor/components/section.h"
#include "CS/section.h"
#include <CS/part.h>
#include <QTabWidget>
#include <QScrollArea>
#include <iostream>

namespace CSEditor {

CSEditor::CSEditor(const CSEditorConfig& config, CS::CS *CSTree, QWidget *parent):
    QWidget(parent),
    contentWgt(config.contentWgt),
    contentLyt(new QVBoxLayout(this)),
    tabWgt(new QTabWidget(this)),
    saveBtn(config.saveBtn),
    importBtn(config.importBtn),
    CSTree(CSTree)
{
    // add the tabWgt in the page
    contentWgt->setLayout(contentLyt);
    contentLyt->addWidget(tabWgt);
    tabWgt->setMovable(false);
    tabWgt->setTabPosition(QTabWidget::South);

    // add parts
    for (CS::Part *part : CSTree->getParts()) {
        tabWgt->addTab(createTab(part), part->getName());
    }

    // the other buttons
    connect(saveBtn, &QPushButton::clicked, this, [&]() { std::cout << "todo" << std::endl; });
    connect(importBtn, &QPushButton::clicked, this, [&]() { std::cout << "todo" << std::endl; });

    setContentsMargins(0, 0, 0, 0);
}

CSEditor::~CSEditor() {
    // remove all widgets (the page is reloaded each time it's open)
    delete contentLyt;
    contentLyt = nullptr;
}

QWidget* CSEditor::createTab(CS::Part* part) {
    QWidget *newTabWgt = new QWidget(tabWgt);
    QVBoxLayout *newTabLyt = new QVBoxLayout(newTabWgt);
    QScrollArea *scrollArea = new QScrollArea(this);

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

} // end namespace CSEditor

#include "cseditor.h"
#include "cseditor/components/section.h"
#include "CS/section.h"
#include <CS/part.h>
#include <QTabWidget>
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
    std::cout << "cseditor constructor" << std::endl;
    // add the tabWgt in the page
    contentWgt->setLayout(contentLyt);
    contentLyt->addWidget(tabWgt);
    tabWgt->setMovable(true);
    tabWgt->setTabPosition(QTabWidget::South);

    // add parts
    for (CS::Part *part : CSTree->getParts()) {
        tabWgt->addTab(createTab(part), part->getName());
    }

    // the other buttons
    connect(saveBtn, &QPushButton::clicked, this, [&]() { std::cout << "todo" << std::endl; });
    connect(importBtn, &QPushButton::clicked, this, [&]() { std::cout << "todo" << std::endl; });
}

CSEditor::~CSEditor() {
    contentWgt->setLayout(nullptr);
    delete contentLyt;
}

QWidget* CSEditor::createTab(CS::Part* part) {
    QWidget *newTabWgt = new QWidget(tabWgt);
    QVBoxLayout *newTabLyt = new QVBoxLayout(newTabWgt);

    for (CS::Section* section : part->getSections()) {
        newTabLyt->addWidget(new Section(section, this));
    }

    newTabWgt->setLayout(newTabLyt);
    newTabLyt->setAlignment(Qt::AlignTop);
    return newTabWgt;
}

} // end namespace CSEditor

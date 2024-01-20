#include "liststatpopup.h"
#include <iostream>

namespace CSCreator {

ListStatPopup::ListStatPopup(const QString& name):
    Popup("LIST STATS"),
    nameEdit(name),
    skillListWgt(new QWidget()),
    skillListLyt(new QVBoxLayout(this)),
    addSkillBtn("+"),
    scrollArea(new QScrollArea(this))
{
    skillListLyt->setAlignment(Qt::AlignTop);
    skillListWgt->setLayout(skillListLyt);
    add(&nameEdit);

    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(skillListWgt);

    add(scrollArea);
    add(&addSkillBtn);

    connect(&addSkillBtn, &QPushButton::clicked, this, [&]() { addSkill(); });
}

ListStatPopup::~ListStatPopup() {
}

void ListStatPopup::addSkill() {
    SkillWgt *newSkill = new SkillWgt("name", "bonus", this);

    connect(newSkill, &SkillWgt::moveUp, this, [&, wgt = newSkill]() { moveSkill(true, wgt); });
    connect(newSkill, &SkillWgt::moveDown, this, [&, wgt = newSkill]() { moveSkill(false, wgt); });
    connect(newSkill, &SkillWgt::remove, this, [&, wgt = newSkill]() { removeSkill(wgt); });
    skillListLyt->addWidget(newSkill);
    skills.push_back(newSkill);
}

void ListStatPopup::addSkill(const QString &name, const QString &bonusStatName) {
    SkillWgt *newSkill = new SkillWgt(name, bonusStatName);
    connect(newSkill, &SkillWgt::moveUp, this, [&, wgt = newSkill]() { moveSkill(true, wgt); });
    connect(newSkill, &SkillWgt::moveDown, this, [&, wgt = newSkill]() { moveSkill(false, wgt); });
    connect(newSkill, &SkillWgt::remove, this, [&, wgt = newSkill]() { removeSkill(wgt); });
    skillListLyt->addWidget(newSkill);
    skills.push_back(newSkill);
}

void ListStatPopup::removeSkill(SkillWgt *wgt) {
    skillListLyt->removeWidget(wgt);
    skills.removeOne(wgt);
    delete wgt;
}

void ListStatPopup::moveSkill(bool up, SkillWgt *wgt) {
    int index = skillListLyt->indexOf(wgt);
    int newIndex = up ? index - 1 : index + 1;

    if (newIndex >= 0 && newIndex < skillListLyt->count()) {
        skillListLyt->removeWidget(wgt);
        skillListLyt->insertWidget(newIndex, wgt);
        // we have to change it in the list of skills as well so there may be a better solution
        skills.removeOne(wgt);
        skills.insert(newIndex, wgt);
    }
}

} // end namespace CSCreator

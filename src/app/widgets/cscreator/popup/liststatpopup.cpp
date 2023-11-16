#include "liststatpopup.h"
#include <iostream>

namespace CSCreator {

ListStatPopup::ListStatPopup():
    CSCreatorPopup("LIST STATS"),
    nameEdit("name"),
    skillListWgt(this),
    addSkillBtn("+")
{
    skillListWgt.setLayout(&skillListLyt);
    add(&nameEdit);
    add(&skillListWgt);
    add(&addSkillBtn);

    connect(&addSkillBtn, &QPushButton::clicked, this, [&]() { addSkill(); });
}

ListStatPopup::~ListStatPopup()
{
    for (auto wgt : skillListLyt.children()) {
        delete wgt;
    }
}

void ListStatPopup::addSkill()
{
    Skill *newSkill = new Skill();
    connect(newSkill, &Skill::moveUp, this, [&, wgt = newSkill]() { moveSkill(true, wgt); });
    connect(newSkill, &Skill::moveDown, this, [&, wgt = newSkill]() { moveSkill(false, wgt); });
    connect(newSkill, &Skill::remove, this, [&, wgt = newSkill]() { removeSkill(wgt); });
    skillListLyt.addWidget(newSkill);
}

void ListStatPopup::removeSkill(QWidget *wgt)
{
    skillListLyt.removeWidget(wgt);
    delete wgt;
}

void ListStatPopup::moveSkill(bool up, QWidget *wgt)
{
    int index = skillListLyt.indexOf(wgt);
    int newIndex = up ? index - 1 : index + 1;

    if (newIndex >= 0 && newIndex < skillListLyt.count()) {
        skillListLyt.removeWidget(wgt);
        skillListLyt.insertWidget(newIndex, wgt);
    }
}

} // end namespace CSCreator

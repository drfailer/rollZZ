#include "liststatpopup.h"
#include <iostream>

namespace CSCreator {

ListStatPopup::ListStatPopup(const QString& name):
    CSCreatorPopup("LIST STATS"),
    nameEdit(name),
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
    for (Skill* wgt : skills) {
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
    skills.push_back(newSkill);
}

void ListStatPopup::addSkill(const QString &name, const QString &bonusStatName)
{
    Skill *newSkill = new Skill(name, bonusStatName);
    connect(newSkill, &Skill::moveUp, this, [&, wgt = newSkill]() { moveSkill(true, wgt); });
    connect(newSkill, &Skill::moveDown, this, [&, wgt = newSkill]() { moveSkill(false, wgt); });
    connect(newSkill, &Skill::remove, this, [&, wgt = newSkill]() { removeSkill(wgt); });
    skillListLyt.addWidget(newSkill);
    skills.push_back(newSkill);
}

void ListStatPopup::removeSkill(Skill *wgt)
{
    skillListLyt.removeWidget(wgt);
    skills.removeOne(wgt);
    delete wgt;
}

void ListStatPopup::moveSkill(bool up, Skill *wgt)
{
    int index = skillListLyt.indexOf(wgt);
    int newIndex = up ? index - 1 : index + 1;

    if (newIndex >= 0 && newIndex < skillListLyt.count()) {
        skillListLyt.removeWidget(wgt);
        skillListLyt.insertWidget(newIndex, wgt);
        // we have to change it in the list of skills as well so there may be a better solution
        skills.removeOne(wgt);
        skills.insert(newIndex, wgt);
    }
}

} // end namespace CSCreator

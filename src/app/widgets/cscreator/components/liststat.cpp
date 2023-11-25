#include "liststat.h"

#include <iostream>
#include <liststatpopup.h>

namespace  CSCreator {

ListStat::ListStat(const QString &name, QWidget *parent):
    Component("Skills List", parent),
    nameLabel("name: " + name),
    skillsWgt(this),
    skillsLyt(&skillsWgt),
    name(name)
{
    bodyAdd(&nameLabel);
    bodyAdd(&skillsWgt);
    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #202020; }"
                  );
    connectSettings();
}

ListStat::ListStat():
    Component("Skills List")
{

}

ListStat::~ListStat()
{
    std::cout << "begin list stat destructor" << std::endl;
    clearSkills();
    std::cout << "end list stat destructor" << std::endl;
}

void ListStat::clearSkills()
{
    // remove the skills
    skills.clear();
    // remove label in the list
    for (QWidget* wgt : skillsLabels) {
        skillsLyt.removeWidget(wgt);
        delete wgt;
    }
    skillsLabels.clear();
}

void ListStat::addSkill(SkillWgt* skill)
{
    QLabel *newLabel = new QLabel(skill->getName()
                                  + " ("
                                  + QString::number(skill->getBonusStat())
                                  + ")");
    skillsLyt.addWidget(newLabel);
    skillsLabels.push_back(newLabel);
    skills.push_back((Skill) { skill->getName(), QString::number(skill->getBonusStat()) });
}

void ListStat::settingsPopup()
{
    if (listStatPopup == nullptr) {
        listStatPopup = new ListStatPopup(name);
        // todo: ajouter liste skills
        for (const Skill& skill : skills) {
            listStatPopup->addSkill(skill.name, skill.statName);
        }
    }
    listStatPopup->show();
    connect(listStatPopup, &ListStatPopup::confirm, this, [&](bool confirm) {
        if (confirm) {
            name = listStatPopup->getName();
            nameLabel.setText("name: " + name);
            clearSkills();
            for (SkillWgt* skill : listStatPopup->getSkills()) {
                addSkill(skill);
            }
        }
        delete listStatPopup;
        listStatPopup = nullptr;
    });
}

} // end namespace CSCreator

#include "liststat.h"

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
    connectSettingFunction(this, [&]() { settingsPopup(); });
}

ListStat::ListStat():
    Component("Skills List")
{

}

ListStat::~ListStat()
{
    clearSkills();
}

void ListStat::clearSkills()
{
    for (auto wgt : skillsLyt.children()) {
        // TODO: find a way to remove the widget in skillsLyt
        delete wgt;
    }
    skills.clear();
}

void ListStat::addSkill(const QString& skillName, const QString& abilityBonuName)
{
    skillsLyt.addWidget(new QLabel(skillName + " (" + abilityBonuName + ")"));
    skills.push_back(SkillStruct{ skillName, abilityBonuName });
}

void ListStat::settingsPopup()
{
    if (listStatPopup == nullptr) {
        listStatPopup = new ListStatPopup(name);
        // todo: ajouter liste skills
        for (SkillStruct skill : skills) {
            listStatPopup->addSkill(skill.name, skill.bonusStatName);
        }
    }
    listStatPopup->show();
    connect(listStatPopup, &ListStatPopup::confirm, this, [&](bool confirm) {
        if (confirm) {
            name = listStatPopup->getName();
            nameLabel.setText("name: " + name);
            clearSkills();
            for (Skill* skill : listStatPopup->getSkills()) {
                addSkill(skill->getName(), QString::number(skill->getBonusStat()));
            }
        }
        delete listStatPopup;
        listStatPopup = nullptr;
    });
}

} // end namespace CSCreator

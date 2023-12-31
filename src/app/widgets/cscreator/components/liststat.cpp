#include "liststat.h"

#include <iostream>
#include <liststatpopup.h>
#include "CS/liststat.h"

namespace  CSCreator {

/******************************************************************************/
/*                         constructors & destructors                         */
/******************************************************************************/

ListStat::ListStat(CS::ListStat *listStat, const QString &name, QWidget *parent):
    Component("Skills List", parent),
    nameLabel("name: " + name),
    skillsWgt(this),
    skillsLyt(&skillsWgt),
    name(name),
    listStat(listStat)
{
    bodyAdd(&nameLabel);
    bodyAdd(&skillsWgt);
    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #202020; }"
                  );
    connectSettings();
}

ListStat::~ListStat()
{
    std::cout << "begin list stat destructor" << std::endl;
    clearSkills();
    std::cout << "end list stat destructor" << std::endl;
}

/******************************************************************************/
/*                                 functions                                  */
/******************************************************************************/

void ListStat::clearSkills()
{
    listStat->clearStats();
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
    listStat->addStat(CS::Caracteristic(skill->getName(), QString::number(skill->getBonusStat())));
}

/******************************************************************************/
/*                                  settings                                  */
/******************************************************************************/

void ListStat::settingsPopup()
{
    if (listStatPopup == nullptr) {
        listStatPopup = new ListStatPopup(name);
        for (const CS::Caracteristic& caracteristic : *listStat) {
            listStatPopup->addSkill(caracteristic.getName(), "");
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

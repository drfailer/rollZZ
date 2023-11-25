#ifndef CSCREATOR_LISTSTAT_H
#define CSCREATOR_LISTSTAT_H

#include "component.h"

namespace CSCreator {

class ListStatPopup;
class SkillWgt;

class ListStat : public Component
{
    Q_OBJECT
public:
    ListStat(const QString& name, QWidget* parent = nullptr);
    ListStat();
    ~ListStat();

    void clearSkills();
    void addSkill(SkillWgt* skill);
    void settingsPopup() override;

private:
    QLabel nameLabel;
    QWidget skillsWgt;
    QVBoxLayout skillsLyt;
    QString name;

    struct Skill {
        QString name;
        QString statName;
    };

    // todo: find a better name
    QList<Skill> skills;
    QList<QLabel*> skillsLabels;

    ListStatPopup* listStatPopup = nullptr;
};

} // end namespace CSCreator

#endif // LISTSTAT_H

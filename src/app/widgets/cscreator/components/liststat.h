#ifndef LISTSTAT_H
#define LISTSTAT_H

#include "component.h"

namespace CSCreator {

class ListStatPopup;

class ListStat : public Component
{
    Q_OBJECT
public:
    ListStat(const QString& name, QWidget* parent = nullptr);
    ListStat();
    ~ListStat();

    void clearSkills();
    void addSkill(const QString& skillName, const QString& abilityBonuName);
    void settingsPopup();

private:
    QLabel nameLabel;
    QWidget skillsWgt;
    QVBoxLayout skillsLyt;
    QString name;

    // todo: find a better name
    struct SkillStruct {
        QString name;
        QString bonusStatName;
    };
    QList<SkillStruct> skills;

    ListStatPopup* listStatPopup = nullptr;
};

} // end namespace CSCreator

#endif // LISTSTAT_H

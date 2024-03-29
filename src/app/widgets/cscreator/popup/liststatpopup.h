#ifndef CSEDITOR_LISTSTATPOPUP_H
#define CSEDITOR_LISTSTATPOPUP_H

#include "tools/popup.h"
#include "tools/listelement.h"
#include "CS/bonusstat.h"
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QList>
#include <QPushButton>
#include <QComboBox>
#include <QScrollArea>

namespace CSCreator {

class SkillWgt;

class ListStatPopup : public Tools::Popup {
    Q_OBJECT
public:
    ListStatPopup(const QString& name = "name");
    ~ListStatPopup();

    QString getName() const { return nameEdit.text(); }
    QList<SkillWgt*> getSkills() const { return skills; }
    void addSkill(const QString &name, const QString &bonusStatName);

private:
    QLineEdit nameEdit;
    QWidget *skillListWgt;
    QVBoxLayout *skillListLyt;
    QPushButton addSkillBtn;
    QScrollArea *scrollArea;
    QList<SkillWgt*> skills;

    void removeSkill(SkillWgt *wgt);
    void moveSkill(bool up, SkillWgt *wgt);
    void addSkill();
};

/******************************************************************************/
/*                                   skill                                    */
/******************************************************************************/

// TODO: move in another file

// subclass for skills:  | name | bunus v |        | X v ^ |
class SkillWgt: public Tools::ListElement {
    Q_OBJECT
public:
    QString getName() const { return nameEdit.text(); }
    int getBonusStat() const { return bonusEdit.currentIndex(); }

    SkillWgt(const QString& name = "name", const QString& bonusStatName = "bonus", QWidget * parent = nullptr):
        Tools::ListElement(parent),
        nameEdit(name)
    {
        if (CS::BonusStat::elements.count()) {
            for (CS::BonusStat *bs : CS::BonusStat::elements) {
                bonusEdit.addItem(bs->getTitle());
            }
        } else {
            bonusEdit.addItem("none");
        }

        bonusEdit.setCurrentText(bonusStatName);

        // left side: | name | bonus v |
        addContent(&nameEdit);
        addContent(&bonusEdit);
    }

private:
    QLineEdit nameEdit;
    QComboBox bonusEdit;
};

} // end namespace CSCreator

#endif // LISTSTATPOPUP_H

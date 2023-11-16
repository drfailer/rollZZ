#ifndef LISTSTATPOPUP_H
#define LISTSTATPOPUP_H

#include "cscreatorpopup.h"
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QList>
#include <QPushButton>
#include <QComboBox>

namespace CSCreator {

class ListStatPopup : public CSCreatorPopup
{
    Q_OBJECT
public:
    ListStatPopup();
    ~ListStatPopup();

private:
    // TODO: add a widget with a QLineEdit and a QComboBox and a + button to add
    //       the name and the BonusStat that corresponds to the added skill.
    QLineEdit nameEdit;
    QWidget skillListWgt;
    QVBoxLayout skillListLyt;
    QPushButton addSkillBtn;

    void removeSkill(QWidget *wgt);
    void moveSkill(bool up, QWidget *wgt);
    void addSkill();
};

// subclass for skills:  | name | bunus v |        | X v ^ |
class Skill: public QWidget {
    Q_OBJECT
public:
    QString getName() const { return nameEdit.text(); }
    int getBonusStat() const { return bonusEdit.currentIndex(); }

    Skill(QWidget * parent = nullptr):
        QWidget(parent),
        mainLyt(this),
        nameEdit("name"),
        upBtn("^"),
        downBtn("v"),
        removeBtn("X")
    {
        mainLyt.addLayout(&configLyt);
        mainLyt.addLayout(&buttonsLyt);

        // left side: | name | bonus v |
        configLyt.addWidget(&nameEdit);
        configLyt.addWidget(&bonusEdit);

        // right side: | X | ^ | v |
        buttonsLyt.addWidget(&removeBtn);
        buttonsLyt.addWidget(&upBtn);
        buttonsLyt.addWidget(&downBtn);

        configLyt.setAlignment(Qt::AlignLeft);
        buttonsLyt.setAlignment(Qt::AlignRight);

        connect(&upBtn, &QPushButton::clicked, this, [&]() { emit moveUp(); });
        connect(&downBtn, &QPushButton::clicked, this, [&]() { emit moveDown(); });
        connect(&removeBtn, &QPushButton::clicked, this, [&]() { emit remove(); });
    }

signals:
    // NOTE(RC): there is a big problem here, this should be refactored
    // in order not to have that much code duplication (the same system
    // is used with the components inside sections).
    void moveUp();
    void moveDown();
    void remove();

private:
    QHBoxLayout mainLyt;
    //---------------------
    QHBoxLayout configLyt;
    QLineEdit nameEdit;
    QComboBox bonusEdit;
    //---------------------
    QHBoxLayout buttonsLyt;
    QPushButton upBtn;
    QPushButton downBtn;
    QPushButton removeBtn;
};

} // end namespace CSCreator

#endif // LISTSTATPOPUP_H

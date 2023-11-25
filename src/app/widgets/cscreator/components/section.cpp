#include "attacks.h"
#include "basicstat.h"
#include "bonusstat.h"
#include "component.h"
#include "descriptor.h"
#include "equipment.h"
#include "liststat.h"
#include "components/section.h"
#include "popup/sectionpopup.h"
#include "popup/basicstatpopup.h"
#include "popup/bonusstatpopup.h"
#include "popup/liststatpopup.h"
#include "popup/descriptorpopup.h"
#include "popup/equipmentpopup.h"
#include "popup/attackspopup.h"
#include <QPalette>
#include <iostream>

namespace CSCreator {

Section::Section(const QString& title, QWidget *parent):
    Component(title, parent),
    addElementBtn(this)
{
    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #222222; }"
                  );

    // body
    bodyAdd(&addElementBtn);
    addElementBtn.addItem("+", int(ComponentTypes::None));
    addElementBtn.addItem("basic stat", int(ComponentTypes::BasicStat));
    addElementBtn.addItem("bonus stat", int(ComponentTypes::BonusStat));
    addElementBtn.addItem("list stat", int(ComponentTypes::ListStat));
    addElementBtn.addItem("descriptor", int(ComponentTypes::Descriptor));
    addElementBtn.addItem("equipment", int(ComponentTypes::Equipment));
    addElementBtn.addItem("attacks & spells", int(ComponentTypes::Attacks));
    addElementBtn.setFixedWidth(43);

    // connect buttons
    connectSettings();
    connect(&addElementBtn, &QComboBox::activated, this, [&](int element) { addElement(ComponentTypes(element)); });
}

Section::~Section()
{
    for (auto wgt : content) {
        delete wgt;
    }
}

void Section::add(QWidget *wgt)
{
    content.push_back(wgt);
    bodyInsert(content.count() - 1, wgt);
}

void Section::move(bool up, QWidget *wgt)
{
    int index = bodyIndexOf(wgt);
    int newIndex = up ? index - 1 : index + 1;

    if (newIndex >= 0 && newIndex < bodyCount() - 1) {
        bodyRemove(wgt);
        bodyInsert(newIndex, wgt);
    }
}

/******************************************************************************/
/* settings button                                                            */
/******************************************************************************/

genSettingsPopup(Section, sectionPopup, SectionPopup,
        setTitle(sectionPopup->getName()), getTitle())

/******************************************************************************/
/* add elements                                                               */
/******************************************************************************/

void Section::addElement(ComponentTypes element)
{
    switch (element) {
    case ComponentTypes::None:
        break;
    case ComponentTypes::BasicStat:
        addBasicStat();
        break;
    case ComponentTypes::BonusStat:
        addBonusStat();
        break;
    case ComponentTypes::ListStat:
        addListStat();
        break;
    case ComponentTypes::Descriptor:
        addDescriptor();
        break;
    case ComponentTypes::Equipment:
        addEquipment();
        break;
    case ComponentTypes::Attacks:
        addAttacks();
        break;
    }
    addElementBtn.setCurrentIndex(int(ComponentTypes::None));
}

#define CreateFunction(popupVar, Component, ...)                                                           \
    Component *Section::create##Component() {                                                              \
        Component *newComponent = new Component(__VA_ARGS__);                                              \
        connect(newComponent, &Section::remove, this, [&, wgt = newComponent]() {                          \
            bodyRemove(wgt); content.removeOne(wgt); delete wgt;                                           \
        });                                                                                                \
        connect(newComponent, &Section::moveUp, this, [&, wgt = newComponent]() { move(true, wgt); });     \
        connect(newComponent, &Section::moveDown, this, [&, wgt = newComponent]() { move(false, wgt); });  \
        return newComponent;                                                                               \
    }
CreateFunction(basicStatPopup, BasicStat, nullptr, basicStatPopup->getMaxValue(), basicStatPopup->getDice(), basicStatPopup->getName(), this)
CreateFunction(bonusStatPopup, BonusStat, nullptr, bonusStatPopup->getMaxValue(), bonusStatPopup->getDice(), bonusStatPopup->getName(), this)
CreateFunction(descriptorPopup, Descriptor, nullptr, descriptorPopup->getName(), this)
CreateFunction(equipmentPopup, Equipment, nullptr, equipmentPopup->getUseWeight(), equipmentPopup->getMaxWeight(), equipmentPopup->getMaxItems(), this)
CreateFunction(attacksPopup, Attacks, nullptr, attacksPopup->getName(), attacksPopup->getMaxItems(), this)
#undef CreateFunction

ListStat *Section::createListStat()
{
    ListStat *newListStat = new ListStat(nullptr, listStatPopup->getName(), this);
    connect(newListStat, &Section::remove, this, [&, wgt = newListStat]() {
        bodyRemove(wgt); content.removeOne(wgt); delete wgt;
    });
    connect(newListStat, &Section::moveUp, this, [&, wgt = newListStat]() { move(true, wgt); });
    connect(newListStat, &Section::moveDown, this, [&, wgt = newListStat]() { move(false, wgt); });
    // add skills
    for (SkillWgt* skill : listStatPopup->getSkills()) {
        newListStat->addSkill(skill);
    }
    return newListStat;
}

#define CreatePopup(Component, popupVar, popupClass)                           \
    void Section::add##Component() {                                           \
        if (popupVar == nullptr) {                                             \
            popupVar = new popupClass();                                       \
        }                                                                      \
        popupVar->show();                                                      \
        connect(popupVar, &popupClass::confirm, this, [&](bool confirm) {      \
            if (confirm) {                                                     \
                add(create##Component());                                      \
            }                                                                  \
            delete popupVar;                                                   \
            popupVar = nullptr;                                                \
        });                                                                    \
    }
CreatePopup(BasicStat, basicStatPopup, BasicStatPopup)
CreatePopup(BonusStat, bonusStatPopup, BonusStatPopup)
CreatePopup(ListStat, listStatPopup, ListStatPopup)
CreatePopup(Descriptor, descriptorPopup, DescriptorPopup)
CreatePopup(Equipment, equipmentPopup, EquipmentPopup)
CreatePopup(Attacks, attacksPopup, AttacksPopup)
#undef CreatePopup

} // end namespace CSCrator

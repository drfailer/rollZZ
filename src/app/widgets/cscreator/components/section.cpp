#include "attacks.h"
#include "basicstat.h"
#include "bonusstat.h"
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
    connectSettingFunction(this, [&]() { settingsPopup(); });
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

void Section::settingsPopup()
{
    if (sectionPopup == nullptr) {
        sectionPopup = new SectionPopup(getTitle());
    }
    sectionPopup->show();
    connect(sectionPopup, &SectionPopup::confirm, this, [&](bool confirm) {
        if (confirm) {
            setTitle(sectionPopup->getName());
        }
        // remove the popup window
        delete sectionPopup;
        sectionPopup = nullptr;
    });
}

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

BasicStat *Section::createBasicStat()
{
    BasicStat *newBasicStat = new BasicStat(basicStatPopup->getMaxValue(),
                                            basicStatPopup->getDice(),
                                            "Basic stat: " + basicStatPopup->getName(),
                                            this);
    connect(newBasicStat, &Section::remove, this, [&, wgt = newBasicStat]() { bodyRemove(wgt); content.removeOne(wgt); delete wgt; });
    connect(newBasicStat, &Section::moveUp, this, [&, wgt = newBasicStat]() { move(true, wgt); });
    connect(newBasicStat, &Section::moveDown, this, [&, wgt = newBasicStat]() { move(false, wgt); });
    return newBasicStat;
}

BonusStat *Section::createBonusStat()
{
    BonusStat *newBonusStat = new BonusStat(bonusStatPopup->getMaxValue(),
                                            bonusStatPopup->getDice(),
                                            "Bonus stat: " + bonusStatPopup->getName(),
                                            this);
    connect(newBonusStat, &Section::remove, this, [&, wgt = newBonusStat]() { bodyRemove(wgt); content.removeOne(wgt); delete wgt; });
    connect(newBonusStat, &Section::moveUp, this, [&, wgt = newBonusStat]() { move(true, wgt); });
    connect(newBonusStat, &Section::moveDown, this, [&, wgt = newBonusStat]() { move(false, wgt); });
    return newBonusStat;
}

ListStat *Section::createListStat()
{
    return nullptr;
}

Descriptor *Section::createDescriptor()
{
    return nullptr;
}

Equipment *Section::createEquipment()
{
    return nullptr;
}

Attacks *Section::createAttacks()
{
    return nullptr;
}

#define CreatePopup(fnName, popupVar, popupClass, createElement)          \
    void Section::fnName() {                                              \
        if (popupVar == nullptr) {                                        \
            popupVar = new popupClass();                                  \
        }                                                                 \
        popupVar->show();                                                 \
        connect(popupVar, &popupClass::confirm, this, [&](bool confirm) { \
            if (confirm) {                                                \
                add(createElement());                                     \
            }                                                             \
            delete popupVar;                                              \
            popupVar = nullptr;                                           \
        });                                                               \
    }
CreatePopup(addBasicStat, basicStatPopup, BasicStatPopup, createBasicStat)
CreatePopup(addBonusStat, bonusStatPopup, BonusStatPopup, createBonusStat)
CreatePopup(addListStat, listStatPopup, ListStatPopup, createListStat)
CreatePopup(addDescriptor, descriptorPopup, DescriptorPopup, createDescriptor)
CreatePopup(addEquipment, equipmentPopup, EquipmentPopup, createEquipment)
CreatePopup(addAttacks, attacksPopup, AttacksPopup, createAttacks)
#undef CreatePopup

} // end namespace CSCrator

#include "cscreator.h"
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
    addElementBtn.addItem("+", None);
    addElementBtn.addItem("basic stat", BasicStat);
    addElementBtn.addItem("bonus stat", BonusStat);
    addElementBtn.addItem("list stat", ListStat);
    addElementBtn.addItem("descriptor", Descriptor);
    addElementBtn.addItem("equipment", Equipment);
    addElementBtn.addItem("attacks & spells", Attacks);
    addElementBtn.setFixedWidth(43);

    // connect buttons
    connectSettingFunction(this, [&]() { settingsPopup(); });
    connect(&addElementBtn, &QComboBox::activated, this, &Section::addElement);
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
    bodyAdd(wgt);
}

void Section::move(bool up, QWidget *wgt)
{
    int index = content.indexOf(wgt);
    int newIndex = up ? index - 1 : index + 1;

    bodyRemove(wgt);
    bodyInsert(newIndex, wgt);
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

void Section::addElement(int element)
{
    switch (element) {
    case None:
        break;
    case BasicStat:
        addBasicStat();
        break;
    case BonusStat:
        addBonusStat();
        break;
    case ListStat:
        addListStat();
        break;
    case Descriptor:
        addDescriptor();
        break;
    case Equipment:
        addEquipment();
        break;
    case Attacks:
        addAttacks();
        break;
    }
    addElementBtn.setCurrentIndex(None);
}

#define CreatePopup(fnName, popupVar, popupClass)                         \
    void Section::fnName() {                                              \
        if (popupVar == nullptr) {                                        \
            popupVar = new popupClass();                                  \
        }                                                                 \
        popupVar->show();                                                 \
        connect(popupVar, &popupClass::confirm, this, [&](bool confirm) { \
            if (confirm) {                                                \
                std::cout << "confirm " #popupClass << std::endl;         \
            }                                                             \
            delete popupVar;                                              \
            popupVar = nullptr;                                           \
        });                                                               \
    }
CreatePopup(addBasicStat, basicStatPopup, BasicStatPopup)
CreatePopup(addBonusStat, bonusStatPopup, BonusStatPopup)
CreatePopup(addListStat, listStatPopup, ListStatPopup)
CreatePopup(addDescriptor, descriptorPopup, DescriptorPopup)
CreatePopup(addEquipment, equipmentPopup, EquipmentPopup)
CreatePopup(addAttacks, attacksPopup, AttacksPopup)
#undef CreatePopup

} // end namespace CSCrator

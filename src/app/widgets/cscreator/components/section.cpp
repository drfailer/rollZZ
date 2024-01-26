#include "attacks.h"
#include "basicstat.h"
#include "bonusstat.h"
#include "component.h"
#include "descriptor.h"
#include "equipment.h"
#include "liststat.h"
#include "components/section.h"
#include "popup/sectionpopup.h"
#include "section.h"
#include <QPalette>

namespace CSCreator {

/******************************************************************************/
/*                          constructor & destructor                          */
/******************************************************************************/

Section::Section(CS::Section* section, QWidget *parent):
    Component(section->getTitle(), parent),
    addElementBtn(this),
    section(section)
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
    connect(&addElementBtn, &QComboBox::activated, this, [&](int element) {
            addElement(ComponentTypes(element));
        });

    // update the compoenents if required
    for (CS::Component *component : section->getComponents()) {
        Component* wgt = createComponent(component);
        connectNewSection(wgt, component);
        appendComponent(wgt);
    }
}

Section::~Section() {
    for (auto wgt : content) {
        delete wgt;
    }
}

/******************************************************************************/
/*                                    add                                     */
/******************************************************************************/



void Section::add(Component *wgt, CS::Component *component) {
    connectNewSection(wgt, component);
    appendComponent(wgt);
    section->addComponent(component);
}

/******************************************************************************/
/*                                    move                                    */
/******************************************************************************/

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

genSettingsPopup(Section, sectionPopup, SectionPopup, {
    setTitle(sectionPopup->getName());
    section->setTitle(sectionPopup->getName());
}, getTitle())

/******************************************************************************/
/* add elements                                                               */
/******************************************************************************/

void Section::addElement(ComponentTypes element)
{
    switch (element) {
    case ComponentTypes::None:
        break;
    case ComponentTypes::BasicStat:
        createElement<BasicStat, CS::BasicStat>();
        break;
    case ComponentTypes::BonusStat:
        createElement<BonusStat, CS::BonusStat>();
        break;
    case ComponentTypes::ListStat:
        createElement<ListStat, CS::ListStat>();
        break;
    case ComponentTypes::Descriptor:
        createElement<Descriptor, CS::Descriptor>();
        break;
    case ComponentTypes::Equipment:
        createElement<Equipment, CS::Equipment>();
        break;
    case ComponentTypes::Attacks:
        createElement<Attacks, CS::Attacks>();
        break;
    }
    addElementBtn.setCurrentIndex(int(ComponentTypes::None));
}

/******************************************************************************/
/*                    create component from CS::Component                     */
/******************************************************************************/

Component *Section::createComponent(CS::Component *component) {
    if (CS::BonusStat* bonusStat = dynamic_cast<CS::BonusStat*>(component)) {
        return new BonusStat(bonusStat, this);
    } else if (CS::BasicStat* basicStat = dynamic_cast<CS::BasicStat*>(component)) {
        return new BasicStat(basicStat, this);
    } else if (CS::ListStat* listStat = dynamic_cast<CS::ListStat*>(component)) {
        return new ListStat(listStat, this);
    } else if (CS::Descriptor* descriptor = dynamic_cast<CS::Descriptor*>(component)) {
        return new Descriptor(descriptor, this);
    } else if (CS::Equipment* equipment = dynamic_cast<CS::Equipment*>(component)) {
        return new Equipment(equipment, this);
    } else if (CS::Attacks* attacks = dynamic_cast<CS::Attacks*>(component)) {
        return new Attacks(attacks, this);
    }
    return nullptr;
}

/******************************************************************************/
/*                             utility functions                              */
/******************************************************************************/

void Section::connectNewSection(Component *wgt, CS::Component *component) {
    connect(wgt, &Section::remove, this, [&, wgt, component] {
        bodyRemove(wgt);
        content.removeOne(wgt);
        section->removeComponent(component);
        delete wgt;
    });
    connect(wgt, &Section::moveUp, this, [&, wgt, component] {
        move(true, wgt);
        this->section->move(true, component);
    });
    connect(wgt, &Section::moveDown, this, [&, wgt, component] {
        move(false, wgt);
        this->section->move(false, component);
    });
}

void Section::appendComponent(Component *wgt) {
    content.push_back(wgt);
    bodyInsert(content.count() - 1, wgt);
}

} // namespace CSCreator

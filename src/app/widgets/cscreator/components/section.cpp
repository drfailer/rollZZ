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

Section::Section(CS::Section* section, const QString& title, QWidget *parent):
    Component(title, parent),
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
    connect(&addElementBtn, &QComboBox::activated, this, [&](int element) { addElement(ComponentTypes(element)); });
}

Section::~Section() {
    for (auto wgt : content) {
        delete wgt;
    }
}

void Section::add(Component *wgt, CS::Component *component) {
    // add connections
    connect(wgt, &Section::remove, this, [&, wgt, component] {
                bodyRemove(wgt);
                content.removeOne(wgt);
                section->removeComponent(component);
                delete wgt;
                delete component;
            });
    connect(wgt, &Section::moveUp, this, [&, wgt] {
                move(true, wgt);
                // TODO: move component in section
            });
    connect(wgt, &Section::moveDown, this, [&, wgt] {
                move(false, wgt);
                // TODO: move component in section
            });

    // add the widget and the compnent to the cstree
    content.push_back(wgt);
    bodyInsert(content.count() - 1, wgt);
    section->addComponent(component);
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

} // end namespace CSCrator

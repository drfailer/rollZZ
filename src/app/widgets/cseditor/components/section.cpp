#include "cseditor/components/attacks.h"
#include "cseditor/components/basicstat.h"
#include "cseditor/components/bonusstat.h"
#include "cseditor/components/component.h"
#include "cseditor/components/descriptor.h"
#include "cseditor/components/equipment.h"
#include "cseditor/components/liststat.h"
#include "cseditor/components/section.h"
#include "CS/section.h"
#include <QPalette>

namespace CSEditor {

Section::Section(CS::Section* section, QWidget *parent):
    Component(section->getTitle(), parent),
    section(section)
{
    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #222222; }"
                  );

    // body
    for (CS::Component* component : section->getComponents()) {
        if (CS::BonusStat* bonusStat = dynamic_cast<CS::BonusStat*>(component)) {
            bodyAdd(new BonusStat(bonusStat, this));
        } else if (CS::BasicStat* basicStat = dynamic_cast<CS::BasicStat*>(component)) {
            bodyAdd(new BasicStat(basicStat, this));
        } else if (CS::ListStat* listStat = dynamic_cast<CS::ListStat*>(component)) {
            bodyAdd(new ListStat(listStat, this));
        } else if (CS::Descriptor* descriptor = dynamic_cast<CS::Descriptor*>(component)) {
            bodyAdd(new Descriptor(descriptor, this));
        } else if (CS::Equipment* equipment = dynamic_cast<CS::Equipment*>(component)) {
            bodyAdd(new Equipment(equipment, this));
        } else if (CS::Attacks* attacks = dynamic_cast<CS::Attacks*>(component)) {
            bodyAdd(new Attacks(attacks, this));
        }
    }
}

Section::~Section() { }

} // end namespace CSCrator

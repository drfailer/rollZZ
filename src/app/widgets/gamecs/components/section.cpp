#include "gamecs/components/attacks.h"
#include "gamecs/components/basicstat.h"
#include "gamecs/components/bonusstat.h"
#include "tools/component.h"
#include "gamecs/components/descriptor.h"
#include "gamecs/components/equipment.h"
#include "gamecs/components/liststat.h"
#include "gamecs/components/section.h"
#include "CS/section.h"
#include <QPalette>

namespace GameCS {

Section::Section(CS::Section* section, QWidget *parent):
    Tools::Component(section->getTitle(), parent),
    section(section)
{
    setStyleSheet("QLabel { font-size: 18px; }"
                  "QPushButton { font-size: 14px; border: 1px solid #282828; border-radius: 5%; }"
                  "QFrame { background-color: #222222; }"
                  );

    // body
    for (CS::Component* component : section->getComponents()) {
        if (CS::BonusStat* bonusStat = dynamic_cast<CS::BonusStat*>(component)) {
            BonusStat *newBonusStat = new BonusStat(bonusStat, this);
            connect(newBonusStat, &BonusStat::rolled, this, [&](QString message) {
                        emit rolled(message);
                    });
            bodyAdd(newBonusStat);
        } else if (CS::BasicStat* basicStat = dynamic_cast<CS::BasicStat*>(component)) {
            bodyAdd(new BasicStat(basicStat, this));
        } else if (CS::ListStat* listStat = dynamic_cast<CS::ListStat*>(component)) {
            ListStat *newListStat = new ListStat(listStat, this);
            connect(newListStat, &ListStat::rolled, this, [&](QString message) {
                        emit rolled(message);
                    });
            bodyAdd(newListStat);
        } else if (CS::Descriptor* descriptor = dynamic_cast<CS::Descriptor*>(component)) {
            bodyAdd(new Descriptor(descriptor, this));
        } else if (CS::Equipment* equipment = dynamic_cast<CS::Equipment*>(component)) {
            bodyAdd(new Equipment(equipment, this));
        } else if (CS::Attacks* attacks = dynamic_cast<CS::Attacks*>(component)) {
            Attacks *newAttacks = new Attacks(attacks, this);
            connect(newAttacks, &Attacks::rolled, this, [&](QString message) {
                        emit rolled(message);
                    });
            bodyAdd(newAttacks);
        }
    }
}

Section::~Section() { }

} // end namespace CSCrator

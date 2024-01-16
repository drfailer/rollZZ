#include "cscreator/components/part.h"
#include "cscreator/components/section.h"
#include "cscreator/popup/sectionpopup.h"

namespace CSCreator {

Part::Part(CS::Part *part, QWidget* parent):
    QWidget(parent),
    part(part),
    newSectionBtn("new section")
{
    layout.addWidget(&newSectionBtn);
    layout.setAlignment(Qt::AlignTop);
    setLayout(&layout);
    connect(&newSectionBtn, &QPushButton::clicked, this, &Part::addSectionPopup);

    // TODO: update the sections if part->sections is not empty
}

// TODO: update the cscreator code

/******************************************************************************/
/*                                add section                                 */
/******************************************************************************/

void Part::addSectionPopup() {
    if (sectionPopup == nullptr) {
        sectionPopup = new SectionPopup();
    }
    sectionPopup->show();
    connect(sectionPopup, &SectionPopup::confirm, this, [&](bool add) {
        if (add) {
            CS::Section* newSection = new CS::Section(sectionPopup->getName());
            Section *newSectionWgt = createSection(newSection);

            layout.insertWidget(layout.count() - 1, newSectionWgt);
            part->addSection(newSection);
        }
        // remove the popup window
        delete sectionPopup;
        sectionPopup = nullptr;
    });
}

/******************************************************************************/
/*                               create section                               */
/******************************************************************************/

Section* Part::createSection(CS::Section *section) {
    Section *sectionWgt = new Section(section, this);

    // connections
    connect(
        sectionWgt, &Section::remove, this, [&, section, wgt = sectionWgt]() {
            part->removeSection(section);
            layout.removeWidget(wgt);
            delete wgt;
        });
    connect(sectionWgt, &Section::moveUp, this,
            [&, wgt = sectionWgt]() { move(true, wgt); });
    connect(sectionWgt, &Section::moveDown, this,
            [&, wgt = sectionWgt]() { move(false, wgt); });

    return sectionWgt;
}

/******************************************************************************/
/*                                    move                                    */
/******************************************************************************/

void Part::move(bool up, QWidget *wgt) {
    int index = layout.indexOf(wgt);
    int newIndex = up ? index - 1 : index + 1;

    if (newIndex >= 0 && newIndex < layout.count() - 1) {
        layout.removeWidget(wgt);
        layout.insertWidget(newIndex, wgt);
    }
}

} // end namespace CSCreator

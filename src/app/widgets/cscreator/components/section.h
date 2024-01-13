#ifndef CSCREATOR_SECTION_H
#define CSCREATOR_SECTION_H

#include "component.h"
#include "CS/section.h"

#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QFrame>

namespace CSCreator {

class Section;
class SectionPopup;

enum class ComponentTypes {
    None = 0,
    BasicStat = 1,
    BonusStat = 2,
    ListStat = 3,
    Descriptor = 4,
    Equipment = 5,
    Attacks = 6,
};

class Section : public Component
{
    Q_OBJECT
public:
    explicit Section(CS::Section* section, QWidget *parent = nullptr);
    ~Section();
    void add(Component *wgt, CS::Component *component);
    void move(bool up, QWidget* wgt);

private slots:
    void settingsPopup() override;
    void addElement(ComponentTypes element);

private:
    QComboBox addElementBtn;
    QList<QWidget*> content;
    CS::Section *section;

    /* popups *****************************************************************/
    SectionPopup *sectionPopup = nullptr;

    /* create elements ********************************************************/
    template<typename WgtT, typename CompT>
    void createElement() {
        CompT *component = new CompT();
        WgtT *wgt = new WgtT(component, this);

        wgt->settingsPopup();
        connect(wgt, &Component::update, this,
                [&, wgt, component](bool confirm) {
                    if (confirm) {
                        add(wgt, component);
                        disconnect(wgt, &Component::update, nullptr, nullptr);
                    } else {
                        delete wgt;
                        delete component;
                    }
                });
    }
};

} // end namespace CSCrator

#endif // CSCREATORSECTION_H

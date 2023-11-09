#ifndef CSCREATORSECTION_H
#define CSCREATORSECTION_H

#include "component.h"

#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QFrame>

namespace CSCreator {

class SectionPopup;
class BasicStatPopup;
class BonusStatPopup;
class ListStatPopup;
class DescriptorPopup;
class EquipmentPopup;
class AttacksPopup;
class Section;
class BasicStat;
class BonusStat;
class ListStat;
class Descriptor;
class Equipment;
class Attacks;

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
    explicit Section(const QString& title, QWidget *parent = nullptr);
    ~Section();
    void add(QWidget* wgt);
    void move(bool up, QWidget* wgt);

private slots:
    void settingsPopup();
    void addElement(ComponentTypes element);
    void addBasicStat();
    void addBonusStat();
    void addListStat();
    void addDescriptor();
    void addEquipment();
    void addAttacks();

private:
    QComboBox addElementBtn;
    QList<QWidget*> content;

    /* popups ******************************************************************/
    SectionPopup *sectionPopup = nullptr;
    BasicStatPopup *basicStatPopup = nullptr;
    BonusStatPopup *bonusStatPopup = nullptr;
    ListStatPopup *listStatPopup = nullptr;
    DescriptorPopup *descriptorPopup = nullptr;
    EquipmentPopup *equipmentPopup = nullptr;
    AttacksPopup *attacksPopup = nullptr;

    /* create elements *********************************************************/
    BasicStat* createBasicStat();
    BonusStat* createBonusStat();
    ListStat* createListStat();
    Descriptor* createDescriptor();
    Equipment* createEquipment();
    Attacks* createAttacks();
};

} // end namespace CSCrator

#endif // CSCREATORSECTION_H

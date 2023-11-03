#ifndef CSCREATOR_H
#define CSCREATOR_H

#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <functional>
#include <iostream>

// the configuration corresponds to the elements on the page that has been created with the designer
struct CSCreatorConfig {
    QWidget *contentWgt;
    QPushButton *newTabBtn;
    QPushButton *saveBtn;
    QPushButton *importBtn;
};

class SectionPopup;
class DescriptorCreationPopup;
class StatCreationPopup;
class EquipmentCreationPopup;
class TabPopup;

class CSCreator : public QWidget
{
    Q_OBJECT
public:
    explicit CSCreator(CSCreatorConfig config, QWidget *parent = nullptr);
    ~CSCreator();
    QWidget* createTab();

public slots:
    /* add bnts ****************************************************************/
    void addTabPopup();
    void renameTabPopup(int index);
    void addSectionPopup();
    void move(bool up, QWidget *wgt);
    // void addDescriptorPopup();
    // void addDescriptor(bool);
    // void addStatPopup();
    // void addStat(bool);
    // void addEquipmentPopup();
    // void addEquipment(bool);

private:
    int index = 0;

    /* elements on the page ****************************************************/
    QWidget *contentWgt;
    QVBoxLayout *contentLyt;
    QTabWidget *tabWgt;
    QPushButton *newTabBtn;
    QPushButton *saveBtn;
    QPushButton *importBtn;
    QList<QWidget*> tabs;

    /* popup menus *************************************************************/
    TabPopup *tabPopup = nullptr;
    SectionPopup *sectionPopup = nullptr;
    DescriptorCreationPopup *descriptorCreationPopup = nullptr;
    StatCreationPopup *statCreationPopup = nullptr;
    EquipmentCreationPopup *equipmentCreationPopup = nullptr;

    QVBoxLayout* currentTabLyt() { return dynamic_cast<QVBoxLayout*>(tabWgt->widget(tabWgt->currentIndex())->layout()); }
};

#endif // CSCREATOR_H

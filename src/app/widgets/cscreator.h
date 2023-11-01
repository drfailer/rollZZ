#ifndef CSCREATOR_H
#define CSCREATOR_H

#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>

// the configuration corresponds to the elements on the page that has been created with the designer
struct CSCreatorConfig {
    QPushButton *addCategoryBtn;
    QPushButton *addDescritorBtn;
    QPushButton *addStatBtn;
    QPushButton *addEquipmentBtn;
    QVBoxLayout *sheetContent;
};

class CategoryCreationPopup;
class DescriptorCreationPopup;
class StatCreationPopup;
class EquipmentCreationPopup;

class CSCreator : public QWidget
{
    Q_OBJECT
public:
    explicit CSCreator(CSCreatorConfig config, QWidget *parent = nullptr);
    ~CSCreator();

private slots:
    /* add bnts ****************************************************************/
    void addCategoryPopup();
    void addCategory(bool);
    void addDescriptorPopup();
    void addDescriptor(bool);
    void addStatPopup();
    void addStat(bool);
    void addEquipmentPopup();
    void addEquipment(bool);

private:
    int index = 0;

    /* elements on the page ****************************************************/
    QPushButton *addCategoryBtn;
    QPushButton *addDescritorBtn;
    QPushButton *addStatBtn;
    QPushButton *addEquipmentBtn;
    QVBoxLayout *sheetContent;

    /* popup menus *************************************************************/
    StatCreationPopup *statCreationPopup = nullptr;
};

#endif // CSCREATOR_H

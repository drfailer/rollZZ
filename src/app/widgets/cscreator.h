#ifndef CSCREATOR_H
#define CSCREATOR_H

#include <QPushButton>
#include <QWidget>
#include <QGridLayout>

// the configuration corresponds to the elements on the page that has been created with the designer
struct CSCreatorConfig {
    QPushButton *addCategoryBtn;
    QPushButton *addDescritorBtn;
    QPushButton *addStatBtn;
    QPushButton *addEquipmentBtn;
    QPushButton *addMoneyBtn;
    QGridLayout *sheetBase;
};

class StatCreationPopup;

class CSCreator : public QWidget
{
    Q_OBJECT
public:
    explicit CSCreator(CSCreatorConfig config, QWidget *parent = nullptr);
    ~CSCreator();

private slots:
    void addStatPopup();
    void addStat();

private:
    int index = 0;

    /* elements on the page ****************************************************/
    QPushButton *addCategoryBtn;
    QPushButton *addDescritorBtn;
    QPushButton *addStatBtn;
    QPushButton *addEquipmentBtn;
    QPushButton *addMoneyBtn;
    QGridLayout *sheetBase;

    /* popup menus *************************************************************/
    StatCreationPopup *statCreationPopup = nullptr;
};

#endif // CSCREATOR_H

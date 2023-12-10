#ifndef CSCREATOR_H
#define CSCREATOR_H

#include "cs.h"
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>


namespace CSCreator {

class TabPopup;
class SectionPopup;

// the configuration corresponds to the elements on the page that has been created with the designer
struct CSCreatorConfig {
    QWidget *contentWgt;
    QPushButton *newTabBtn;
    QPushButton *saveBtn;
    QPushButton *importBtn;
};

class CSCreator : public QWidget
{
    Q_OBJECT
public:
    CS::CS* getCSTree() const { return CSTree; }
    explicit CSCreator(CSCreatorConfig config, QWidget *parent = nullptr);
    ~CSCreator();
    QWidget* createTab();

public slots:
    /* add bnts ****************************************************************/
    void addTabPopup();
    void renameTabPopup(int index);
    void addSectionPopup();
    void move(bool up, QWidget *wgt);

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

    /* cs tree *****************************************************************/
    CS::CS* CSTree;

    /* private methods *********************************************************/
    QVBoxLayout* currentTabLyt() { return dynamic_cast<QVBoxLayout*>(tabWgt->widget(tabWgt->currentIndex())->layout()); }
};

} // end namespace CSCreator

#endif // CSCREATOR_H

#ifndef CSCREATOR_H
#define CSCREATOR_H

#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <functional>
#include <iostream>

class TabPopup;
class SectionPopup;

namespace CSCreator {

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

    /* private methods *********************************************************/
    QVBoxLayout* currentTabLyt() { return dynamic_cast<QVBoxLayout*>(tabWgt->widget(tabWgt->currentIndex())->layout()); }
};

} // end namespace CSCreator

#endif // CSCREATOR_H

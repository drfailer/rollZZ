#ifndef CSCREATOR_H
#define CSCREATOR_H

#include "cs.h"
#include "part.h"
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QMap>
#include <QScrollArea>

namespace CSCreator {

class TabPopup;
class SectionPopup;
class Section;
class Component;

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
    explicit CSCreator(CSCreatorConfig config, CS::CS *CSTree = nullptr, QWidget *parent = nullptr);
    ~CSCreator();
    QWidget* createTab(const QString& name);
    void reload();
    void reloadPart(CS::Part *part);

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
    QMap<QWidget*, CS::Part*> parts;

    /* popup menus *************************************************************/
    TabPopup *tabPopup = nullptr;
    SectionPopup *sectionPopup = nullptr;

    /* cs tree *****************************************************************/
    CS::CS* CSTree = nullptr;

    /* private methods *********************************************************/

    Section *createSection(CS::Section *section);
    Component *createComponent(CS::Component *component);

    QScrollArea* createScrollArea() {
        QScrollArea *scrollArea = new QScrollArea(this);

        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        return scrollArea;
    }

    QWidget* getTabWgt(int index) {
        QScrollArea *scrollArea = dynamic_cast<QScrollArea*>(tabWgt->widget(index));
        return scrollArea->widget();
    }

    QVBoxLayout* currentTabLyt() {
        return dynamic_cast<QVBoxLayout*>(getTabWgt(tabWgt->currentIndex())->layout());
    }
};

} // end namespace CSCreator

#endif // CSCREATOR_H

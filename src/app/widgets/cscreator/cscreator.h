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
class Part;
class FileSelectorPopup;

// the configuration corresponds to the elements on the page that has been created with the designer
struct CSCreatorConfig {
    QWidget *contentWgt;
    QPushButton *newTabBtn;
    QPushButton *saveBtn;
    QPushButton *importBtn;
};

class CSCreator : public QWidget {
    Q_OBJECT
public:
    CS::CS* getCSTree() const { return CSTree; }
    explicit CSCreator(CSCreatorConfig config, CS::CS *CSTree = nullptr, QWidget *parent = nullptr);
    ~CSCreator();

public slots:
    /* add bnts ****************************************************************/
    void addTabPopup();
    void renameTabPopup(int index);
    void loadTemplateFile();
    void saveTemplateFile();

private:
    int index = 0;

    /* elements on the page ****************************************************/
    QWidget *contentWgt;
    QVBoxLayout *contentLyt;
    QTabWidget *tabWgt;
    QPushButton *newTabBtn;
    QPushButton *saveBtn;
    QPushButton *importBtn;

    /* popup menus *************************************************************/
    TabPopup *tabPopup = nullptr;
    SectionPopup *sectionPopup = nullptr;
    FileSelectorPopup* fileSelectorPopup = nullptr;

    /* cs tree *****************************************************************/
    CS::CS* CSTree = nullptr;

    /* private methods *********************************************************/

    QWidget* createTab(const QString& name);
    void reload();
    void reloadPart(CS::Part *part);
    void clearTabs();
    QScrollArea *createScrollArea();
    Part *getPart(int index);
};

} // end namespace CSCreator

#endif // CSCREATOR_H

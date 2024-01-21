#ifndef CSEDITOR_H
#define CSEDITOR_H

#include "cs.h"
#include "part.h"
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QMap>
#include <QString>


namespace CSEditor {

class TabPopup;
class SectionPopup;

// the configuration corresponds to the elements on the page that has been created with the designer
struct CSEditorConfig {
    QWidget *contentWgt;
    QPushButton *saveBtn;
    QPushButton *importBtn;
    QString csFile;
};

class CSEditor : public QWidget
{
    Q_OBJECT
public:
    CS::CS* getCSTree() const { return CSTree; }
    explicit CSEditor(const CSEditorConfig& config, CS::CS *CSTree = nullptr, QWidget *parent = nullptr);
    ~CSEditor();

private:
    int index = 0;

    /* elements on the page ****************************************************/
    QWidget *contentWgt;
    QVBoxLayout *contentLyt;
    QTabWidget *tabWgt;
    QPushButton *saveBtn;
    QPushButton *importBtn;

    /* cs tree *****************************************************************/
    CS::CS* CSTree = nullptr;
    QString csFile = "";

    /* private methods *********************************************************/
    QVBoxLayout* currentTabLyt() { return dynamic_cast<QVBoxLayout*>(tabWgt->widget(tabWgt->currentIndex())->layout()); }
    QWidget* createTab(CS::Part* part);
};

} // end namespace CSEditor

#endif // CSEDITOR_H

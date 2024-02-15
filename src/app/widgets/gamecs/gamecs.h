#ifndef GAMECS_H
#define GAMECS_H

#include "cs.h"
#include "part.h"
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QMap>
#include <QString>


namespace GameCS {

class TabPopup;
class SectionPopup;

class GameCS : public QWidget {
    Q_OBJECT
public:
    GameCS(const QString& csFile = "", CS::CS *CSTree = nullptr);
    ~GameCS();

    /* accessors **************************************************************/
    CS::CS* getCSTree() const { return CSTree; }
    QString getCSFile() const { return csFile; }

private:
    int index = 0;

    /* elements on the page ***************************************************/
    QVBoxLayout *contentLyt;
    QTabWidget *tabWgt;
    QPushButton *saveBtn;

    /* cs tree ****************************************************************/
    CS::CS* CSTree = nullptr;
    QString csFile = "";

    /* private methods ********************************************************/
    QVBoxLayout* currentTabLyt() { return dynamic_cast<QVBoxLayout*>(tabWgt->widget(tabWgt->currentIndex())->layout()); }
    QWidget* createTab(CS::Part* part);
};

} // end namespace GameCS

#endif // GAMECS_H

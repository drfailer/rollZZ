#ifndef GAMECS_H
#define GAMECS_H

#include "cs.h"
#include "part.h"
#include <QMap>
#include <QPushButton>
#include <QString>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

namespace GameCS {

class TabPopup;
class SectionPopup;

class GameCS : public QWidget {
    Q_OBJECT
  public:
    GameCS(const QString &csFile = "");
    ~GameCS();

    /* accessors **************************************************************/
    QString getCSFile() const { return csFile; }

  signals:
    void rolled(QString message);

  private:
    int index = 0;

    /* elements on the page ***************************************************/
    QVBoxLayout *contentLyt;
    QTabWidget *tabWgt;
    QPushButton *saveBtn;

    /* cs tree ****************************************************************/
    CS::CS CSTree;
    QString csFile = "";

    /* private methods ********************************************************/
    QVBoxLayout *currentTabLyt() {
        return dynamic_cast<QVBoxLayout *>(
            tabWgt->widget(tabWgt->currentIndex())->layout());
    }
    QWidget *createTab(CS::Part *part);
};

} // end namespace GameCS

#endif // GAMECS_H

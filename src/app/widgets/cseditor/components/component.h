#ifndef CSEDITOR_COMPONENT_H
#define CSEDITOR_COMPONENT_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include <qlineedit.h>

namespace CSEditor {

class Component : public QFrame
{
  Q_OBJECT
public:
    Component(const QString& title, QWidget *parent = nullptr);
    virtual ~Component() {}

    /* methods ******************************************************************/
    void bodyAdd(QWidget *wgt);
    void bodyRemove(QWidget *wgt);
    void bodyInsert(int index, QWidget *wgt);
    int  bodyCount() const { return bodyLyt.count(); }
    int  bodyIndexOf(QWidget *wgt) const { return bodyLyt.indexOf(wgt); }

    /* accessors ****************************************************************/
    QString getTitle() const { return title.text(); }
    void    setTitle(const QString &newTitle) { title.setText(newTitle); }

private:
    QVBoxLayout mainLyt;
    QHBoxLayout headerLyt;
    QVBoxLayout bodyLyt;
    QLineEdit   title;
    QHBoxLayout titleLyt;
};

} // end namespace CSEditor

#endif // COMPONENT_H

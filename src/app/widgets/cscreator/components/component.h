#ifndef COMPONENT_H
#define COMPONENT_H

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFrame>
#include <QString>
#include <functional>

#include <iostream>

namespace CSCreator {

class Component : public QFrame
{
    Q_OBJECT
public:
    explicit Component(const QString& title, QWidget *parent = nullptr);
    virtual ~Component() {}

    /* methods ****************************************************************/
    void bodyAdd(QWidget* wgt);
    void bodyRemove(QWidget* wgt);
    void bodyInsert(int index, QWidget *wgt);
    int bodyCount() const { return bodyLyt.count(); }
    int bodyIndexOf(QWidget* wgt) const { return bodyLyt.indexOf(wgt); }

    /* accessors ***************************************************************/
    QString getTitle() const { return title.text(); }
    void setTitle(const QString& newTitle) { title.setText(newTitle); }

    /* setting function ********************************************************/
    void connectSettingFunction(Component* wgt, std::function<void()> function);

signals:
    void moveUp();
    void moveDown();
    void remove();

private: // NOTE: everything should not be protected
    QVBoxLayout mainLyt;
    QHBoxLayout headerLyt; // contains the title and the buttons
    QVBoxLayout bodyLyt;
    QLabel title;
    QHBoxLayout titleLyt;
    QHBoxLayout btnsLyt;
    QPushButton removeBtn;
    QPushButton moveUpBtn;
    QPushButton moveDownBtn;
    QPushButton settingsBtn;
};

} // end namespace CSCreator

#endif // COMPONENT_H

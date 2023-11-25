#ifndef CSCREATOR_COMPONENT_H
#define CSCREATOR_COMPONENT_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include <functional>

namespace CSCreator {

class Component : public QFrame
{
  Q_OBJECT
public:
    explicit Component(const QString &title, QWidget *parent = nullptr);
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

    /* setting function *********************************************************/
    virtual void settingsPopup() = 0;
    void         connectSettings();

signals:
    void moveUp();
    void moveDown();
    void remove();

private: // NOTE: everything should not be protected
    QVBoxLayout mainLyt;
    QHBoxLayout headerLyt; // contains the title and the buttons
    QVBoxLayout bodyLyt;
    QLabel      title;
    QHBoxLayout titleLyt;
    QHBoxLayout btnsLyt;
    QPushButton removeBtn;
    QPushButton moveUpBtn;
    QPushButton moveDownBtn;
    QPushButton settingsBtn;
};

#define genSettingsPopup(Class, popupVar, PopupClass, confirmCode, ...)        \
    void Class::settingsPopup() {                                              \
        if (popupVar == nullptr) {                                             \
            popupVar = new PopupClass(__VA_ARGS__);                            \
        }                                                                      \
        popupVar->show();                                                      \
        connect(popupVar, &PopupClass::confirm, this, [&](bool confirm) {      \
            if (confirm) confirmCode;                                          \
            delete popupVar;                                                   \
            popupVar = nullptr;                                                \
        });                                                                    \
    }

} // end namespace CSCreator

#endif // COMPONENT_H

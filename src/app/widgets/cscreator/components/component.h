#ifndef COMPONENT_H
#define COMPONENT_H

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFrame>
#include <QString>
#include <functional>

namespace CSCreator {

class Component : public QFrame
{
    Q_OBJECT
public:
    explicit Component(const QString& title, QWidget *parent = nullptr);

    /* methods ****************************************************************/
    void bodyAdd(QWidget* wgt);
    void bodyRemove(QWidget* wgt);
    void bodyInsert(int index, QWidget *wgt);

    /* accessors ***************************************************************/
    QString getTitle() const { return title.text(); }
    void setTitle(const QString& newTitle) { title.setText(newTitle); }

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

protected:
    void connectSettingFunction(Component* wgt, std::function<void()> function);
};

} // end namespace CSCreator

#endif // COMPONENT_H

#ifndef LISTELEMENT_H
#define LISTELEMENT_H

#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>

namespace Tools {

class ListElement : public QWidget
{
    Q_OBJECT
public:
    ListElement(QWidget * parent = nullptr);

    void addContent(QWidget* wgt);

signals:
    // NOTE(RC): there is a big problem here, this should be refactored
    // in order not to have that much code duplication (the same system
    // is used with the components inside sections).
    void moveUp();
    void moveDown();
    void remove();

private:
    QHBoxLayout mainLyt;
    //---------------------
    QHBoxLayout contentLyt;
    //---------------------
    QHBoxLayout buttonsLyt;
    QPushButton upBtn;
    QPushButton downBtn;
    QPushButton removeBtn;
};

} // end namespace Tools

#endif // LISTELEMENT_H

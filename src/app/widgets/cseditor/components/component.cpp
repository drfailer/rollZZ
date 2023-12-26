#include "component.h"

namespace CSEditor {

Component::Component(const QString& title, QWidget *parent):
    QFrame(parent),
    mainLyt(this),
    title(title)
{
    headerLyt.addLayout(&titleLyt);

    // title on the right
    titleLyt.addWidget(&this->title);

    // alignement
    titleLyt.setAlignment(Qt::AlignLeft);
    // bodyLyt.setAlignment(Qt::AlignLeft);

    // add to the main layout
    mainLyt.addLayout(&headerLyt);
    mainLyt.addLayout(&bodyLyt);
}

void Component::bodyAdd(QWidget *wgt)
{
    bodyLyt.addWidget(wgt);
}

void Component::bodyRemove(QWidget *wgt)
{
    bodyLyt.removeWidget(wgt);
}

void Component::bodyInsert(int index, QWidget *wgt)
{
    bodyLyt.insertWidget(index, wgt);
}

} // end namespace CSEditor

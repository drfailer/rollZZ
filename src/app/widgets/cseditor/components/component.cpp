#include "component.h"

namespace CSEditor {

/******************************************************************************/
/*                                constructor                                 */
/******************************************************************************/

Component::Component(const QString &title, QWidget *parent)
    : QFrame(parent), mainLyt(this), title(title) {
    headerLyt.addLayout(&titleLyt);

    // title on the right
    titleLyt.addWidget(&this->title);

    // alignement
    titleLyt.setAlignment(Qt::AlignLeft);
    // bodyLyt.setAlignment(Qt::AlignLeft);

    // add to the main layout
    mainLyt.addLayout(&headerLyt);
    mainLyt.addLayout(&bodyLyt);

    // remove content margins
    setContentsMargins(0, 0, 0, 0);
}

/******************************************************************************/
/*                                 functions                                  */
/******************************************************************************/

void Component::bodyAdd(QWidget *wgt) { bodyLyt.addRow(wgt); }

void Component::bodyAdd(const QString& description, QWidget *wgt) {
    bodyLyt.addRow(description, wgt);
}

void Component::bodyRemove(QWidget *wgt) { bodyLyt.removeRow(wgt); }

void Component::bodyInsert(int index, QWidget *wgt) {
    bodyLyt.insertRow(index, wgt);
}

} // end namespace CSEditor

#include "tools/popup.h"

namespace Tools {

/******************************************************************************/
/*                                constructor                                 */
/******************************************************************************/

Popup::Popup(const QString& name):
    QWidget(nullptr),
    mainLyt(this),
    title(name),
    confirmBtn("confirm"),
    cancelBtn("cancel")
{
    mainLyt.addWidget(&title);
    // body
    mainLyt.addLayout(&bodyLyt);
    // cancle / confirm
    btnLyt.addWidget(&cancelBtn);
    btnLyt.addWidget(&confirmBtn);
    mainLyt.addLayout(&btnLyt);

    // connect btns
    connect(&confirmBtn, &QPushButton::clicked, this, [&]() {
        emit confirm(true);
    });
    connect(&cancelBtn, &QPushButton::clicked, this, [&]() {
        emit confirm(false);
    });
    mainLyt.setAlignment(Qt::AlignTop);
    bodyLyt.setAlignment(Qt::AlignTop|Qt::AlignLeft);

    // style
    setStyleSheet("QWidget { color: #F2F2F2; background-color: #1B1B1B; }");
}

/******************************************************************************/
/*                                    add                                     */
/******************************************************************************/

void Popup::add(QWidget *wgt) {
    bodyLyt.addRow(wgt);
}

void Popup::add(const QString& description, QWidget *wgt) {
    bodyLyt.addRow(description, wgt);
}

} // end namespace Tools

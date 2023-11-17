#include "listelement.h"

namespace Tools {

ListElement::ListElement(QWidget *parent):
    QWidget(parent),
    mainLyt(this),
    upBtn("^"),
    downBtn("v"),
    removeBtn("X")
{
    mainLyt.addLayout(&contentLyt);
    mainLyt.addLayout(&buttonsLyt);

    // right side: | X | ^ | v |
    buttonsLyt.addWidget(&removeBtn);
    buttonsLyt.addWidget(&upBtn);
    buttonsLyt.addWidget(&downBtn);

    contentLyt.setAlignment(Qt::AlignLeft);
    buttonsLyt.setAlignment(Qt::AlignRight);

    connect(&upBtn, &QPushButton::clicked, this, [&]() { emit moveUp(); });
    connect(&downBtn, &QPushButton::clicked, this, [&]() { emit moveDown(); });
    connect(&removeBtn, &QPushButton::clicked, this, [&]() { emit remove(); });
}

void ListElement::addContent(QWidget *wgt)
{
    contentLyt.addWidget(wgt);
}

} // end namespace Tools

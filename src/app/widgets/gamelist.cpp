#include "gamelist.h"

#include <QPushButton>

GameList::GameList(const QList<QString>& games, QWidget *parent):
    QWidget(parent),
    games(games)
{
    setLayout(&layout);

    // adding the elements in the list of games
    if (games.empty()) {
        // the text is in black ???
        // TODO: paint it in white !
        layout.addWidget(new QLabel("Na game available"), Qt::AlignLeft|Qt::AlignTop);
    } else {
        for (QString elt : games) {
            layout.addWidget(new QPushButton(elt));
            // TODO: connect button
            // TODO: change the stylesheet
        }
        // layout.setAlignment(Qt::AlignHCenter|Qt::AlignTop);
    }
}

GameList::~GameList()
{
    for (auto *widget : layout.children()) {
        delete widget;
    }
}

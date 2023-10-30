#include "gamelist.h"

#include <QPushButton>

GameList::GameList(const QList<QString>& games, QWidget *parent):
    QWidget(parent),
    games(games)
{
    setLayout(&layout);

    // adding the elements in the list of games
    if (games.empty()) {
        layout.addWidget(new QLabel("No game available"), Qt::AlignLeft|Qt::AlignTop);
    } else {
        // marche pas et je ne comprends pas pk
        layout.setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        for (const QString& elt : games) {
            layout.addWidget(new QPushButton(elt));
            // TODO: connect button
            // TODO: change the stylesheet
        }
    }
}

GameList::~GameList()
{
    for (auto *widget : layout.children()) {
        delete widget;
    }
}

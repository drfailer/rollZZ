#include "gamelist.h"


#include <QMainWindow>
#include <QPushButton>
#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

GameList::GameList(const QList<map::Game*>& games, QWidget *parent, std::function<void(const map::Game*)> launchGame):
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
        for (const map::Game* elt : games) {
            QPushButton* btn = new QPushButton(elt->getName());
            layout.addWidget(btn);
            connect(btn, &QPushButton::clicked, this, [=](){launchGame(elt);});
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

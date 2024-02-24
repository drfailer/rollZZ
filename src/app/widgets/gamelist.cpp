#include "gamelist.h"


#include <QMainWindow>
#include <QPushButton>
#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

GameList::GameList(const QList<Game*>& games, QWidget *parent):
    QWidget(parent),
    games(games)
{
    // problem when we add a new game... idk why
    layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop);

    if (games.empty()) {
        layout->addWidget(new QLabel("No game available"));
    } else {
        for (Game* elt : games) {
            QPushButton* btn = new QPushButton(elt->getName());
            layout->addWidget(btn);
            connect(btn, &QPushButton::clicked, this, [=](){emit setGame(elt);});
        }
    }
}

void GameList::addGame(Game* game)
{
    QPushButton* btn = new QPushButton(game->getName());
    layout->addWidget(btn);
    connect(btn, &QPushButton::clicked, this, [=](){emit setGame(game);});
}

GameList::~GameList()
{
}


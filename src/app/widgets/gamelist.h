#ifndef GAMELIST_H
#define GAMELIST_H

#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "game.h"

class GameList : public QWidget
{
    Q_OBJECT
public:
    explicit GameList(const QList<map::Game*>& games,QWidget *parent,std::function<void(const map::Game* game)> launchGame);
    ~GameList();

private:
    // TODO: we use string for testing but this will be real games (or at least,
    // we will build a list of buttons with the player's games)
    QList<map::Game*> games;
    QVBoxLayout layout;
};

#endif // GAMELIST_H

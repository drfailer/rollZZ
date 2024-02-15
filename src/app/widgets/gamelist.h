#ifndef GAMELIST_H
#define GAMELIST_H

#include "cs.h"
#include "gamecs/gamecs.h"
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "game.h"

class GameList : public QWidget
{
    Q_OBJECT
public:
    explicit GameList(const QList<map::Game*>& games,QWidget *parent);
    ~GameList();

public: signals:
    // Useless parameters, since the parameters of the signal are given as paremters to the slots/lambda
    // else we should create a signal in our game class,
    // and call  QObject::sender() to retreive the class and the game value
    void setGame(map::Game* game =nullptr);


private:
    // TODO: we use string for testing but this will be real games (or at least,
    // we will build a list of buttons with the player's games)
    QList<map::Game*> games;
    QVBoxLayout layout;

    CS::CS CSTree;
    GameCS::GameCS *gameCS = nullptr;
};

#endif // GAMELIST_H

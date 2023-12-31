#include "game.h"

map::Game::Game(QString name):name(name)
{}

QString map::Game::getName() const {
    return name;
}

Map map::Game::getMap() const {
    return map;
}

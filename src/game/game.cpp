#include "game.h"

Game::Game(QString name):name(name), maps(std::vector<Map*>{new Map()})
{}

QString Game::getName() const {
    return name;
}

Map* Game::getDefaultMap() const {
    return maps[0];
}

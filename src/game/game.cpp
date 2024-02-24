#include "game.h"

Game::Game(QString mj, QString _name):
SERIALIZER(name,maps,MJ_uuid),
name(_name), maps(std::vector<Map*>{new Map()}), MJ_uuid(mj)
{}

void Game::setName(const QString& str)
{
    name = str;
}

QString Game::getName() const {
    return name;
}

Map* Game::getDefaultMap() const {
    return maps[0];
}

void Game::load(const QString& fileName) {
    deserializeFile((DirectoriesPath + fileName).toStdString());
}

void Game::save()
{
    serializeFile((DirectoriesPath + name).toStdString());
}

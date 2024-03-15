#include "game.h"

Game::Game(QString mj, QString _name):
SERIALIZER(name, maps, MJ_uuid),
name(_name), MJ_uuid(mj)
{
    QString filePath = GAME_DIRECTORY;
    QDir dir(filePath);
    dir.mkdir(name);
    Map* m = new Map(name);
    m->save();
    maps = std::vector<Name*>{new Name(m->getName())};
}

void Game::setName(const QString& str)
{
    name;
}

QString Game::getName() const {
    return name;
}

QString Game::getDefaultMap() const {
    return maps[0]->getName();
}

QString Game::getMJUuid() const
{
    return MJ_uuid;
}

void Game::load()
{
    deserializeFile((GAME_DIRECTORY + name + "/" + name + "_game").toStdString());
}

void Game::load(QString name)
{
    deserializeFile((GAME_DIRECTORY + name + "/" + name + "_game").toStdString());
}

void Game::save()
{
    QDir dir;
    dir.mkdir(GAME_DIRECTORY + name);
    serializeFile((GAME_DIRECTORY + name + "/" + name + "_game").toStdString());
}

#ifndef GAME_H
#define GAME_H

#include <QString>
#include "map.h"
#include "serializer.hpp"
#include <QDir>

#define DirectoriesPath QDir::homePath() + QString("/.local/resources/games/")

class Game
{
    SERIALIZABLE_WITH_CONVERTOR(QtConvertor,QString,std::vector<Map*>,QString)
public:
    Game(QString mj = " ", QString name = "");
    QString getName() const;
    void setName(const QString&);
    void load(const QString&);
    void save();
    Map* getDefaultMap() const;
private:
  QString name;
  std::vector<Map*> maps;
  QString MJ_uuid;
};

#endif // GAME_H


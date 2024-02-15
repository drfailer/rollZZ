#ifndef GAME_H
#define GAME_H

#include <QString>
#include "map.h"

class Game
{
public:
    Game(QString name);
    QString getName() const;
    Map* getDefaultMap() const;
private:
  QString name;
  std::vector<Map*> maps;
};

#endif // GAME_H


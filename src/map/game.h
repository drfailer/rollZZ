#ifndef GAME_H
#define GAME_H

#include <QString>
#include "map.h"

namespace map
{
class Game
{
public:
    Game(QString name);
    QString getName() const;
    Map getMap() const;
private:
    QString name;
    Map map;
};

#endif // GAME_H

}

#ifndef GAME_H
#define GAME_H

#include <QString>
#include "map.h"
#include "serializer.hpp"
#include <QDir>
#include "name.h"

class Game
{
    SERIALIZABLE_WITH_CONVERTOR(QtConvertor,QString,std::vector<Name*>,QString)
public:
    Game(QString mj = " ", QString name = "");
    QString getName() const;
    QString getMJUuid() const ;
    void setName(const QString&);
    void load();
    void load(QString name);
    void save();
    QString getDefaultMap() const;
private:
  QString name;
  std::vector<Name*> maps;
  QString MJ_uuid;
};

#endif // GAME_H


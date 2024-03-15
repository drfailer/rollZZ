#ifndef MAP_H
#define MAP_H

#include "mapelement.h"
#include "serializable.hpp"
#include "tools/qtconvertor.h"
#include "config.h"

class Map
{
  SERIALIZABLE_WITH_CONVERTOR(QtConvertor,QString,QString,std::list<MapElement*>,std::list<MapElement*>)
public:
  Map(QString gameName="default",QString name="default");

  QString getName(){return name;}
  QString getGameName() const {return gameName;}
  std::list<MapElement*> getMap(){return map;}
  const std::list<MapElement*> getmapElementsUse() const {return mapElementsUse;}

  MapElement* addElementUse(QString filePath,QString name) {
    MapElement* el = new MapElement(filePath,name);
    mapElementsUse.push_back(el);
    return el;}

  void addElementOnMap(MapElement* el) {
    map.push_back(el);}

  void removeElementOnMap(MapElement* el) {
    map.remove(el);}

  void load();
  void save();
private:
  QString name;
  QString gameName;
  std::list<MapElement*> map;
  std::list<MapElement*> mapElementsUse;
};
#endif // MAP_H

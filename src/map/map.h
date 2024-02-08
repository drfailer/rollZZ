#ifndef MAP_H
#define MAP_H

#include "mapelement.h"
#include "serializable.hpp"
#include "qtconvertor.h"

class Map
{
  SERIALIZABLE_WITH_CONVERTOR(QtConvertor,std::list<MapElement*>,std::list<MapElement*>)
public:
    Map();
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

    void load(const QString& filePath);
    void save(const QString& filePath);
private:
    std::list<MapElement*> map;
    std::list<MapElement*> mapElementsUse;
};
#endif // MAP_H

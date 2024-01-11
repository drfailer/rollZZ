#ifndef MAP_H
#define MAP_H

#include "mapelement.h"


// Right now, I think we have a problem (pointer or not)
// Do we change element (mapElement, QPixmap) as a pointer (to avoid copy when it's the same)
// But in this case, what happen when we change one of the mapElement...
class Map
{
public:
    Map();
    std::vector<MapElement> getMap(){return map;}
    const std::vector<MapElement*> getmapElementsUse() const {return mapElementsUse;}
    MapElement* addElementUse(QString filePath,QString name) {
      MapElement* el = new MapElement(filePath,name);
      mapElementsUse.push_back(el);
      return el;}
private:
    std::vector<MapElement> map;
    std::vector<MapElement*> mapElementsUse;
};
#endif // MAP_H

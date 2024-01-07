#ifndef MAP_H
#define MAP_H

#include "mapelement.h"


// Right now, I think we have a problem (pointer or not)
// Do we change element (mapElement, QPixmap) as a pointer (to avoid copy when it's the same)
// But in this case, what happen when we change one of the mapElement...
class Map
{
public:
    Map(int mapElementSize=64,std::pair<int,int> maxmapElementsNbr={24,12});
    std::pair<int,int> getMaxmapElementsNbr() const {return maxmapElementsNbr;}
    int getmapElementsSize() const {return mapElementSize;}
    std::vector<MapElement> getMap(){return map;}
    const std::vector<MapElement*> getmapElementsUse() const {return mapElementsUse;}
private:
    // TODO: Pointer === better
    std::vector<MapElement> map;
    std::vector<MapElement*> mapElementsUse;
    int mapElementSize;
    std::pair<int,int> maxmapElementsNbr;
};
#endif // MAP_H

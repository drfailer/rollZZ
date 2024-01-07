#include "map.h"

Map::Map(int mapElementSize,std::pair<int,int> maxmapElementsNbr):mapElementSize(mapElementSize),maxmapElementsNbr(maxmapElementsNbr)
{
    mapElementsUse = std::vector<MapElement*>{new MapElement(":ressources/tiles/wall")};
    map= std::vector<MapElement>();
}

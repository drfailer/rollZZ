#include "map.h"

Map::Map()
{
    mapElementsUse = std::vector<MapElement*>{new MapElement(":ressources/tiles/wall")};
    mapElementsUse[0]->RescalePixMap(64,64);
    map= std::vector<MapElement>();
}

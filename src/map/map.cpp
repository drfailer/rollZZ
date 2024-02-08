#include "map.h"

Map::Map():SERIALIZER(map, mapElementsUse)
{
  MapElement* m = new MapElement(":ressources/tiles/wall");
  m->RescalePixMap(64,64);
    mapElementsUse = std::list<MapElement*>{m};
    map= std::list<MapElement*>();
}


void Map::load(const QString& fileName) {
    deserializeFile(fileName.toStdString());
    for (MapElement * el :map)
      el->updateImage();
    for (MapElement * el :mapElementsUse)
    {
      el->updateImage();
      el->RescalePixMap(64,64);
    }
}

void Map::save(const QString& fileName) {
    serializeFile(fileName.toStdString());
}

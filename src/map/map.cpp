#include "map.h"

Map::Map(QString _gameName,QString _name):SERIALIZER(name,gameName,map, mapElementsUse),
                                             name(_name),gameName(_gameName)
{
  MapElement* m = new MapElement(":ressources/tiles/wall");
  mapElementsUse = std::list<MapElement*>{m};
  map= std::list<MapElement*>();
}


void Map::load() {
  deserializeFile((GAME_DIRECTORY + gameName + "/" + name).toStdString());
  for (MapElement * el :map)
    el->updateImage();
  for (MapElement * el :mapElementsUse)
  {
    el->updateImage();
    el->RescalePixMap(64,64);
  }
}

void Map::save() {
  serializeFile((GAME_DIRECTORY + gameName + "/" + name).toStdString());
}

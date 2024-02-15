#ifndef MAPPLAYERTOKEN_HPP
#define MAPPLAYERTOKEN_HPP

#include "gamecs/gamecs.h"
#include "mapgraphicsitem.h"

class MapPlayerToken : public MapGraphicsItem {
  public:
    MapPlayerToken(MapElement* mapElement, QGraphicsItem *parent = nullptr);
    ~MapPlayerToken() = default;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

  private:
    GameCS::GameCS *cs = nullptr;
};

#endif

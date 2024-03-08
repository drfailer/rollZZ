#ifndef MAPPLAYERTOKEN_HPP
#define MAPPLAYERTOKEN_HPP

#include "gamecs/gamecs.h"
#include "mapgraphicsitem.h"

class MapPlayerToken : public MapGraphicsItem {
    Q_OBJECT
  public:
    MapPlayerToken(MapElement *mapElement, QGraphicsItem *parent = nullptr);
    ~MapPlayerToken() = default;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

  signals:
    void rolled(QString message);

  private:
    GameCS::GameCS *cs = nullptr;
};

#endif

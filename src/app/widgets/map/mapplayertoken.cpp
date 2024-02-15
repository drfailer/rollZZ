#include "map/mapplayertoken.h"
#include "config.h"

MapPlayerToken::MapPlayerToken(MapElement* mapElement, QGraphicsItem *parent):
    MapGraphicsItem(mapElement, parent)
{
}

void MapPlayerToken::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton) {
        if (cs != nullptr) {
            delete cs;
        }
        cs = new GameCS::GameCS(CS_DIRECTORY + "/Talion");
        cs->show();
    }
}

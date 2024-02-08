#ifndef MAPGRAPHICSSCENE_H
#define MAPGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDropEvent>
#include <QWidget>
#include "map.h"
#include "mapgraphicsitem.h"
#include <QMimeData>
#include <QCoreApplication>
#include <QGraphicsSceneMouseEvent>
#include <QTimeLine>
#include <set>

class MapGraphicsScene: public QGraphicsScene
{
  Q_OBJECT
public:
  MapGraphicsScene(QWidget* parent);
  qreal getScale() const;
  void setActualZValue(int i){actualZValue = i; if(selectedItem) {selectedItem->setZValue(i); previousZValue = i;} }
  void dropEvent(QGraphicsSceneDragDropEvent *event);
  void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
  void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
  void deleteSelected();
  void insertNewGraphicsElement(MapElement* mapElementToDrop,bool isNewEvent);
signals:
  void dropEventSignal(MapGraphicsItem* dropItem,bool isNewEvent);
  void dragEnterEventSignal(QDragEnterEvent *event) ;
  void dragMoveEventSignal(QDragMoveEvent *event);
public slots:
      void focusItem(MapGraphicsItem* el);

private:
  int actualZValue;
  int previousZValue;
  MapGraphicsItem* selectedItem;
  int sceneSizeX,sceneSizeY;
};

#endif // MAPGRAPHICSSCENE_H

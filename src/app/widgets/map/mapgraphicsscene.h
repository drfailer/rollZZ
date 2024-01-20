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

class MapGraphicsScene: public QGraphicsScene
{
  Q_OBJECT
public:
  MapGraphicsScene(QWidget* parent);
  qreal getScale() const;
  void dropEvent(QGraphicsSceneDragDropEvent *event);
  void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
  void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
  void keyPressEvent(QKeyEvent *event) override;
signals:
  void dropEventSignal(QDropEvent *event);
  void dragEnterEventSignal(QDragEnterEvent *event) ;
  void dragMoveEventSignal(QDragMoveEvent *event);
public slots:
      void focusItem(MapGraphicsItem* el);

private:
  MapGraphicsItem* selectedItem;
  QVector<MapGraphicsItem*> items;
  int sceneSizeX,sceneSizeY;
};

#endif // MAPGRAPHICSSCENE_H

#ifndef MAPGRAPHICSITEM_H
#define MAPGRAPHICSITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsObject>
#include <QMouseEvent>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include "handle.h"
#include "mapelement.h"

class MapGraphicsItem : public QGraphicsObject
{
Q_OBJECT
public:
  MapGraphicsItem(MapElement* mapElement, QGraphicsItem *parent = nullptr);
  void unselected();
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
  bool isSelected() const {return selected;}
  void setSelected(bool);
  MapElement* getMapElement() const {return mapElement;}
  ~MapGraphicsItem();
signals:
  void mousePressedSignal(MapGraphicsItem* el);

public slots:
  void prepareForRescale(QPointF scenePos);
  void rescale(QPointF newPosition,CORNER corner);
  void endRescale();

private:
    QGraphicsItem* selectedHandle;
    QVector<Handle*> scaleHandles;
    QRectF borderRect;
    qreal borderSize = 4.0;
    MapElement* mapElement;
    bool resizing;
    bool selected;
};

#endif // MAPGRAPHICSITEM_H

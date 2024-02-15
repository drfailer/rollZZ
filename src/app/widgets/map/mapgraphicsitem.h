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
  bool isSelected() const {return selected;}
  void setSelected(bool);
  void setSize();
  void setZValue(int i) {
    QGraphicsObject::setZValue(i);
    mapElement->setLayer(i);}
  MapElement* getMapElement() const {return mapElement;}

  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
  QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
  ~MapGraphicsItem();

signals:
  void mousePressedSignal(MapGraphicsItem* el);
  void deleteSignal();

public slots:
  void rescale(QPointF newPosition,CORNER corner);
  void endRescale();

private:
    QVector<Handle*> scaleHandles;
    QRectF borderRect;
    qreal borderSize = 4.0;
    MapElement* mapElement;
    bool selected;
};

#endif // MAPGRAPHICSITEM_H

#ifndef HANDLE_H
#define HANDLE_H

#include <QGraphicsItem>
#include <QCursor>
#include <QPainter>
#include <QGraphicsSceneEvent>

enum CORNER
{
  TOP_LEFT,
  TOP,
  TOP_RIGHT,
  RIGHT,
  BOTTOM_RIGHT,
  BOTTOM,
  BOTTOM_LEFT,
  LEFT,
  ROTATE
};

class Handle: public QGraphicsObject
{
Q_OBJECT
public:
  Handle(QGraphicsObject* parent,CORNER corner);
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
  QRectF boundingRect() const override;
  void hoverEnterEvent(QGraphicsSceneHoverEvent*);
  void hoverLeaveEvent(QGraphicsSceneHoverEvent*);
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

signals:
  void mousePressSignal(QPointF);
  void mouseMoveSignal(QPointF,CORNER);
  void mouseReleaseSignal();

private:
  CORNER corner;
};

#endif // HANDLE_H

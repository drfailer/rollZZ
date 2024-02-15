#include "handle.h"
#include <iostream>

Handle::Handle(QGraphicsObject* parent, CORNER corner): QGraphicsObject(parent),corner(corner)
{
  setAcceptHoverEvents(true);
  setAcceptTouchEvents(true);
  setFlags(QGraphicsItem::ItemIsSelectable);
}

QRectF Handle::boundingRect() const
{
  return QRectF(-10, -10, 20, 20);
}

void Handle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  Q_UNUSED(option);
  Q_UNUSED(widget);

  painter->setBrush(Qt::red);
  painter->drawRect(boundingRect());
}

void Handle::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
  setCursor(QCursor(Qt::OpenHandCursor));
  QGraphicsObject::hoverEnterEvent(event);
}

void Handle::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
  setCursor(QCursor(Qt::ArrowCursor));
  QGraphicsObject::hoverEnterEvent(event);
}

void Handle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  emit mouseMoveSignal(event->scenePos(),corner);
  QGraphicsObject::mouseMoveEvent(event);
}

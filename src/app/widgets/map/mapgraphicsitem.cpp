#include "mapgraphicsitem.h"

#include <iostream>

MapGraphicsItem::MapGraphicsItem(MapElement* mapElement,QGraphicsItem* parent):QGraphicsObject(parent),mapElement(mapElement)
{
  QPixmap pixmap = mapElement->getOriginalPixMap();
  borderRect = QRectF(-borderSize/2,-borderSize/2, pixmap.width()+borderSize, pixmap.height()+borderSize);
  scaleHandles = QVector<Handle*>(5);
  setFlags(QGraphicsItem::ItemIsSelectable|
           QGraphicsItem::ItemIsMovable);
  setAcceptHoverEvents(true);

}

QRectF MapGraphicsItem::boundingRect() const
{
  // Can have a problem with the border, seem the border don't contain everything when we zoom a lot, no problem is we stay on pixmap.rect()
  // I think it come from the fact that rect width grow when we zoom;
  return borderRect;
}

void MapGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr)
{
  Q_UNUSED(option);
  Q_UNUSED(widget);

  QPixmap pixmap = mapElement->getOriginalPixMap();
  painter->drawPixmap(borderRect, pixmap,pixmap.rect());
  if (isSelected())
  {
    QPen pen = QPen(Qt::cyan);
    pen.setWidth(borderSize);
    painter->setPen(pen);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(borderRect);
  }
}

void MapGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
  if(event->buttons()== Qt::LeftButton)
  {
      setSelected(true);
  }
  QGraphicsObject::mousePressEvent(event);
}

void MapGraphicsItem::setSelected(bool b)
{
  if (b && !selected)
  {
  QRectF border = boundingRect();

  scaleHandles[0] = new Handle(this,TOP_LEFT);
  scaleHandles[0]->setPos(border.topLeft());
  scaleHandles[1] = new Handle(this,TOP_RIGHT);
  scaleHandles[1]->setPos(border.topRight());

  scaleHandles[2] = new Handle(this,BOTTOM_RIGHT);
  scaleHandles[2]->setPos(border.bottomRight());
  scaleHandles[3]= new Handle(this,BOTTOM_LEFT);
  scaleHandles[3]->setPos(border.bottomLeft());
  scaleHandles[4]= new Handle(this,ROTATE);
  scaleHandles[4]->setPos(border.center().x(),border.topLeft().y()-20);


  for(Handle* handle : scaleHandles)
  {
      connect(handle,&Handle::mousePressSignal,this,&MapGraphicsItem::prepareForRescale);
      connect(handle,&Handle::mouseMoveSignal,this,&MapGraphicsItem::rescale);
  }

  selected = true;
  emit mousePressedSignal(this);
  }
  else
  emit mousePressedSignal(nullptr);
}

void MapGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsObject::mouseMoveEvent(event);
}

void MapGraphicsItem::unselected()
{
  selected = false;
  for(Handle* h: scaleHandles)
    delete h;
}

void MapGraphicsItem::prepareForRescale(QPointF scenePos)
{
  std::cout << "prepareforrescale" << std::endl;
  resizing = true;
}

void MapGraphicsItem::rescale(QPointF newPosition,CORNER corner)
{
    if (resizing)
    {
    QPointF posInItem = mapFromScene(newPosition);

    QLineF line;
    double rotations;

    // Not exactly the right coordinate (we can squeeze more bottom right than top left
    // not urgent to change it
    switch (corner)
    {
    case TOP_LEFT:
      if(posInItem.x() < borderRect.width() && posInItem.y() < borderRect.height())
        borderRect.setTopLeft(posInItem);
      break;
    case TOP_RIGHT:
      if(posInItem.x() > borderRect.x() && posInItem.y() < borderRect.height())
        borderRect.setTopRight(posInItem);
      break;
    case BOTTOM_RIGHT:
      if(posInItem.x() > borderRect.x() && posInItem.y() > borderRect.y())
        borderRect.setBottomRight(posInItem);
      break;
    case BOTTOM_LEFT:
      if(posInItem.x() < borderRect.y() && posInItem.y() > borderRect.y())
        borderRect.setBottomLeft(posInItem);
      break;
    case ROTATE:
      line = QLine(borderRect.center().toPoint(), posInItem.toPoint());
      rotations = line.angleTo(QLineF(0, 0, 0, -1));

      qDebug() << "rotations " << rotations;
      // idk why, but the first input always turn 90 left

      setTransformOriginPoint(borderRect.center());
      setRotation(rotation() + rotations);

      qDebug() << "transformOriginPoint()" << transformOriginPoint();
      qDebug() << "sceneBoundingRect()" << sceneBoundingRect();
      break;
    default:
      break;
    }

    prepareGeometryChange();
    update();

    QRectF border = boundingRect();
    scaleHandles[0]->setPos(border.topLeft());
    scaleHandles[1]->setPos(border.topRight());
    scaleHandles[2]->setPos(border.bottomRight());
    scaleHandles[3]->setPos(border.bottomLeft());
    scaleHandles[4]->setPos(border.center().x(),border.topLeft().y()-20);
    }
}


void MapGraphicsItem::endRescale()
{
    prepareGeometryChange();
    update();
    resizing = false;
}



MapGraphicsItem::~MapGraphicsItem()
{
  for(Handle* h: scaleHandles)
    delete h;
}


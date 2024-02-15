#include "mapgraphicsitem.h"

#include <iostream>

MapGraphicsItem::MapGraphicsItem(MapElement* mapElement,QGraphicsItem* parent):QGraphicsObject(parent),mapElement(mapElement)
{
  QPixmap pixmap = mapElement->getOriginalPixMap();
  borderRect = QRectF(0,0, mapElement->getSize().width(), mapElement->getSize().height());
  scaleHandles = QVector<Handle*>(5);

  setRotation(mapElement->getRotation());
  setPos(mapElement->getPos());
  setZValue(mapElement->getLayer());

  setFlags(QGraphicsItem::ItemIsSelectable|
           QGraphicsItem::ItemIsMovable|
           QGraphicsItem::ItemSendsGeometryChanges);
  setAcceptHoverEvents(true);
}

QRectF MapGraphicsItem::boundingRect() const
{return borderRect;}

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
    setSelected(true);

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
    connect(handle,&Handle::mouseMoveSignal,this,&MapGraphicsItem::rescale);

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

void MapGraphicsItem::setSize()
{
  mapElement->setSize(borderRect.size().width(),borderRect.size().height());
}

void MapGraphicsItem::rescale(QPointF newPosition,CORNER corner)
{
  QPointF posInItem = mapFromScene(newPosition);
  QLineF line;
  double rotations;

  switch (corner)
  {
  case TOP_LEFT:
    if(posInItem.x() < borderRect.right() && posInItem.y() < borderRect.bottom()) {
      borderRect.setTopLeft(posInItem);
      setSize();}
    break;
  case TOP_RIGHT:
    if(posInItem.x() > borderRect.x() && posInItem.y() < borderRect.bottom()) {
      borderRect.setTopRight(posInItem);
      setSize();}
    break;
  case BOTTOM_RIGHT:
    if(posInItem.x() > borderRect.x() && posInItem.y() > borderRect.y()) {
      borderRect.setBottomRight(posInItem);
      setSize(); }
    break;
  case BOTTOM_LEFT:
    if(posInItem.x() < borderRect.right() && posInItem.y() > borderRect.y()) {
      borderRect.setBottomLeft(posInItem);
      setSize();}
    break;
    // Strange effect rotation after scaling
  case ROTATE:
    line = QLine(borderRect.center().toPoint(), posInItem.toPoint());
    rotations = line.angleTo(QLineF(0, 0, 0, -1)) + rotation();
    setTransformOriginPoint(borderRect.center());
    setRotation(rotations);
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

void MapGraphicsItem::endRescale()
{
    prepareGeometryChange();
    update();
}

MapGraphicsItem::~MapGraphicsItem()
{
  for(Handle* h: scaleHandles)
    delete h;
}

QVariant MapGraphicsItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
  //std::cout << "changement: " << change << std::endl;
  if (change == ItemPositionHasChanged) {
    QPointF newPos = value.toPointF();
    mapElement->setPos(newPos.x(),newPos.y());
  }
  if(change == ItemRotationHasChanged)
    mapElement->setRotate(value.toFloat());
  return QGraphicsItem::itemChange(change, value);
}


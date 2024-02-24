#include "mapgraphicsscene.h"
#include<iostream>

MapGraphicsScene::MapGraphicsScene(QWidget* parent):QGraphicsScene(parent), actualZValue(0),sceneSizeX(500),sceneSizeY(500)
{
  setSceneRect(0,0,sceneSizeX,sceneSizeY);
  QGraphicsItem *rectItem = new QGraphicsRectItem(0,0,sceneSizeX,sceneSizeY);
  addItem(rectItem);
  selectedItem = nullptr;
  previousZValue = 0;
}

void MapGraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
  if (event->mimeData()->hasFormat("map-element"))
  {
    event->acceptProposedAction();
    QPoint dropPos = event->pos().toPoint();
    Qt::KeyboardModifiers modifiers = event->modifiers();
    emit dragEnterEventSignal(new QDragEnterEvent(dropPos, event->proposedAction(), event->mimeData(),event->buttons(),modifiers));
  }
}

void MapGraphicsScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
  if (event->mimeData()->hasFormat("map-element"))
  {
    event->acceptProposedAction();

    QPoint dropPos = event->scenePos().toPoint();
    Qt::KeyboardModifiers modifiers = event->modifiers();

    emit dragMoveEventSignal(new QDragMoveEvent(dropPos, event->proposedAction(), event->mimeData(),event->buttons(), modifiers));
  }
}

void MapGraphicsScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
  QPointF scenePoint = event->scenePos();
  const QMimeData* mimeData = event->mimeData();
  QByteArray byteArray = mimeData->data("map-element");
  QDataStream inStream(byteArray);
  MapElement* mapElementToDrop = new MapElement();
  inStream >> mapElementToDrop;
  mapElementToDrop->setPos(scenePoint.x()-mapElementToDrop->getSize().width()/2,scenePoint.y()-mapElementToDrop->getSize().height()/2);
  mapElementToDrop->setLayer(actualZValue);

  event->accept();

 insertNewGraphicsElement(mapElementToDrop);
}

void MapGraphicsScene::insertNewGraphicsElement(MapElement* mapElementToDrop)
{
  MapGraphicsItem* el = new MapGraphicsItem(mapElementToDrop);
  addItem(el);
  connect(el,&MapGraphicsItem::mousePressedSignal,this,&MapGraphicsScene::focusItem);

  emit dropEventSignal(el);
}

void MapGraphicsScene::focusItem(MapGraphicsItem* el)
{
  if(selectedItem)
  {
    selectedItem->setZValue(previousZValue);
    selectedItem->unselected();
  }
  if(el)
  {
  selectedItem = el;
  previousZValue = selectedItem->zValue();
  selectedItem->setZValue(2);
  }
  else
  selectedItem = nullptr;
 }

void MapGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
  if (event->button() == Qt::LeftButton)
  {
    QGraphicsItem * item = itemAt(event->scenePos(),QTransform());

    if(selectedItem == item || (item && item->parentItem() == selectedItem))
    {
    }
    else if (selectedItem)
    {
      selectedItem->setZValue(previousZValue);
      selectedItem->unselected();
      selectedItem = nullptr;
    }
  }
  QGraphicsScene::mousePressEvent(event);
}

void MapGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsScene::mouseMoveEvent(event);
}

void MapGraphicsScene::deleteSelected()
{
  if(selectedItem)
  {
    emit selectedItem->deleteSignal();
    delete selectedItem;
    selectedItem = nullptr;
  }
}

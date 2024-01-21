#include "mapgraphicsscene.h"
#include<iostream>

MapGraphicsScene::MapGraphicsScene(QWidget* parent):QGraphicsScene(parent), sceneSizeX(2500),sceneSizeY(2500)
{
  setSceneRect(0,0,sceneSizeX,sceneSizeY);
  QGraphicsItem *rectItem = new QGraphicsRectItem(0,0,sceneSizeX,sceneSizeY);
  addItem(rectItem);
  items = QVector<MapGraphicsItem*>();
  selectedItem = nullptr;
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
  MapGraphicsItem* el;

  const QMimeData* mimeData = event->mimeData();
  QByteArray byteArray = mimeData->data("map-element");
  QDataStream inStream(byteArray);
  MapElement* mapElementToDrop = new MapElement();
  inStream >> mapElementToDrop;

  int elementSizeX = mapElementToDrop->getPixMap().size().width(),
      elementSizeY = mapElementToDrop->getPixMap().size().height();

  if(scenePoint.x() + elementSizeX/2 <= sceneSizeX && scenePoint.x() - elementSizeX/2 >= 0 && scenePoint.y() + elementSizeY/2 <= sceneSizeY && scenePoint.y() - elementSizeY/2 >= 0 )
  {
    std::cout << "|"<< mapElementToDrop->getFilePath().toStdString() << "|" << std::endl;

    // TODO: TAKE the original image, not the image we use to print on the menu
    // IDK why, doesn't work with this line
    //el = new MapGraphicsItem(QPixmap(mapElementToDrop->getFilePath()));
    el = new MapGraphicsItem(mapElementToDrop);
    addItem(el);
    items.push_back(el);
    items.back()->setPos(scenePoint.x()-elementSizeX/2,scenePoint.y()-elementSizeY/2);
    connect(items.back(),&MapGraphicsItem::mousePressedSignal,this,&MapGraphicsScene::focusItem);
  }
  event->accept();

  QPointF dropPos = event->scenePos();
  Qt::DropActions proposedAction = event->possibleActions();
  Qt::KeyboardModifiers modifiers = event->modifiers();

  emit dropEventSignal(new QDropEvent(dropPos, proposedAction, event->mimeData(),event->buttons(),modifiers),el);
}

void MapGraphicsScene::focusItem(MapGraphicsItem* el)
{
  if(selectedItem && selectedItem != el)
  {
    selectedItem->unselected();
  }
  selectedItem = el;
}

void MapGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
  if (event->button() == Qt::LeftButton)
  {
    QGraphicsItem * item = itemAt(event->scenePos(),QTransform());

    std::cout << "item " <<item << std::endl;

    if(item) std::cout << " parent item " << item->parentItem() << std::endl;
    std::cout << "selected item " << selectedItem << std::endl;
    if(selectedItem == item || (item && item->parentItem() == selectedItem))
    {
    std::cout << "same or parent" << std::endl;
    }
    else if (selectedItem)
    {
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

void MapGraphicsScene::keyPressEvent(QKeyEvent *event)
{
  if (event->key() == Qt::Key_Delete && selectedItem)
  {delete selectedItem;
    selectedItem = nullptr;
  }
}

#include "mapgraphicsview.h"

MapGraphicsView::MapGraphicsView(QWidget* parent):QGraphicsView(parent)
{
    setMinimumSize(QSize(500,500));
    setAcceptDrops(true);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    viewport()->setAcceptDrops(true);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 250,250);
    QGraphicsItem *rectItem = new QGraphicsRectItem(0, 0, 250, 250);
    scene->addItem(rectItem);
    setScene(scene);
    items = std::vector<QGraphicsPixmapItem*>();
}

void MapGraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("map-element"))
    {
        event->acceptProposedAction();
      emit dragEnterEventSignal(event);
    }
}

void MapGraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("map-element"))
    {
        event->acceptProposedAction();
        emit dragMoveEventSignal(event);
    }
}

void MapGraphicsView::dropEvent(QDropEvent *event)
{
    QPointF scenePoint = mapToScene(event->pos());

    const QMimeData* mimeData = event->mimeData();
    QByteArray byteArray = mimeData->data("map-element");
    QDataStream inStream(byteArray);
    MapElement* mapElementToDrop = new MapElement();
    inStream >> mapElementToDrop;

    int elementSizeX = mapElementToDrop->getPixMap().size().width(),
        elementSizeY = mapElementToDrop->getPixMap().size().height();

    if(scenePoint.x() + elementSizeX/2 <= 250 && scenePoint.x() - elementSizeX/2 >= 0 && scenePoint.y() + elementSizeY/2 <= 250 && scenePoint.y() - elementSizeY/2 >= 0 )
    {
    items.push_back(scene->addPixmap(mapElementToDrop->getPixMap()));
    items.back()->setPos(scenePoint.x()-elementSizeX/2,scenePoint.y()-elementSizeY/2);
    }
    event->accept();
     emit dropEventSignal(event);
}

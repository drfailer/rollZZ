#include "mapgraphicsview.h"

MapGraphicsView::MapGraphicsView(QWidget* parent):QGraphicsView(parent), numScheduledScalings(0), sceneSizeX(2500),sceneSizeY(2500)
{
  setMinimumSize(QSize(500,500));
  setAcceptDrops(true);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  viewport()->setAcceptDrops(true);
  scene = new QGraphicsScene(this);
  scene->setSceneRect(0,0,sceneSizeX,sceneSizeY);
  QGraphicsItem *rectItem = new QGraphicsRectItem(0,0,sceneSizeX,sceneSizeY);
  scene->addItem(rectItem);
  setScene(scene);
  setTransformationAnchor(QGraphicsView::NoAnchor);
  items = std::vector<QGraphicsPixmapItem*>();
  selectionBorder = selectedItem = nullptr;
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
  QPointF scenePoint = mapToScene(event->position().toPoint());

  const QMimeData* mimeData = event->mimeData();
  QByteArray byteArray = mimeData->data("map-element");
  QDataStream inStream(byteArray);
  MapElement* mapElementToDrop = new MapElement();
  inStream >> mapElementToDrop;

  int elementSizeX = mapElementToDrop->getPixMap().size().width(),
      elementSizeY = mapElementToDrop->getPixMap().size().height();

  if(scenePoint.x() + elementSizeX/2 <= sceneSizeX && scenePoint.x() - elementSizeX/2 >= 0 && scenePoint.y() + elementSizeY/2 <= sceneSizeY && scenePoint.y() - elementSizeY/2 >= 0 )
  {
    items.push_back(scene->addPixmap(mapElementToDrop->getPixMap()));
    items.back()->setPos(scenePoint.x()-elementSizeX/2,scenePoint.y()-elementSizeY/2);
  }
  event->accept();
  emit dropEventSignal(event);
}

void MapGraphicsView::wheelEvent ( QWheelEvent * event )
{
  // See the QWheelEvent doc
  // Most mouse wheel turn 15 degree per rotation.
  // And 8*15=120°
  int numDegrees = event->angleDelta().y()/8;
  int numSteps = numDegrees / 15;
  numScheduledScalings += numSteps;
 if (numScheduledScalings * numSteps < 0)
 numScheduledScalings = numSteps;

 QTimeLine *anim = new QTimeLine(350, this);
 anim->setUpdateInterval(20);

 connect(anim, SIGNAL (valueChanged(qreal)), SLOT (scalingTime(qreal)));
 connect(anim, SIGNAL (finished()), SLOT (animFinished()));
 anim->start();

}

void MapGraphicsView::scalingTime(qreal x)
{
 qreal factor = 1.0+ qreal(numScheduledScalings) / 300.0;
 scale(factor, factor);

}

void MapGraphicsView::animFinished()
{
 if (numScheduledScalings > 0)
    numScheduledScalings--;
 else
    numScheduledScalings++;
 sender()->~QObject();
}

void MapGraphicsView::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::RightButton)
    {
        // Store original position.
        mousePosOriginX = event->pos().x();
        mousePosOriginY = event->pos().y();
    }
    else if(event->button() == Qt::LeftButton)
    {
        if(selectionBorder)
        {
          delete selectionBorder;
          selectionBorder = nullptr;
        }

        QPointF mousePosition = mapToScene(event->pos());
        //Maybe use items later to get all layers
      QGraphicsItem* item = scene->itemAt(mousePosition.toPoint(),transform());

      if (item)
      {
          QPen pen = QPen(Qt::cyan);
          pen.setWidth(8);
        QSizeF elementSize = item->boundingRect().size();
        if(elementSize.width() > 0)
          selectionBorder = scene->addRect(item->pos().x(),item->pos().y(),elementSize.width(),elementSize.height(),pen);
        selectedItem = item;
      }
    }
}

void MapGraphicsView::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() == Qt::RightButton)
    {
        QPointF oldPoint = mapToScene(mousePosOriginX, mousePosOriginY);
        QPointF newPoint = mapToScene(event->pos());
        QPointF translation = newPoint - oldPoint;

        translate(translation.x(), translation.y());

        mousePosOriginX = event->pos().x();
        mousePosOriginY = event->pos().y();
        event->accept();
    }
}

void MapGraphicsView::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Delete && selectedItem)
    {

        delete selectedItem;
        delete selectionBorder;
        selectedItem = nullptr;
        selectionBorder = nullptr;

    }
}

qreal MapGraphicsView::getScale() const { return transform().m11();}

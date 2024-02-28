#include "mapgraphicsview.h"

MapGraphicsView::MapGraphicsView(QWidget* parent):QGraphicsView(parent), numScheduledScalings(0), sceneSizeX(200),sceneSizeY(200)
{
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  setMinimumSize(0, 0);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  viewport()->setAcceptDrops(true);
  scene = new MapGraphicsScene(this);
  setScene(scene);
  setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
  setTransformationAnchor(QGraphicsView::NoAnchor);
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
 Q_UNUSED(x);

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
      mousePosOrigin = event->pos();

    QGraphicsView::mousePressEvent(event);
}

void MapGraphicsView::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() == Qt::RightButton)
    {
    QPointF newPoint = event->pos();
    QPointF translation = newPoint - mousePosOrigin;
    translate(translation.x(), translation.y());
    mousePosOrigin = event->pos();
    }
    QGraphicsView::mouseMoveEvent(event);
}

qreal MapGraphicsView::getScale() const { return transform().m11();}

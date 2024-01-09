#ifndef MAPGRAPHICSVIEW_H
#define MAPGRAPHICSVIEW_H


#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDropEvent>
#include <QWidget>
#include "map.h"
#include <QMimeData>
#include <QCoreApplication>
#include <QTimeLine>

class MapGraphicsView: public QGraphicsView
{
  Q_OBJECT
public:
    MapGraphicsView(QWidget* parent);
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void wheelEvent ( QWheelEvent * event ) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
  signals:
    void dropEventSignal(QDropEvent *event);
    void dragEnterEventSignal(QDragEnterEvent *event) ;
    void dragMoveEventSignal(QDragMoveEvent *event);
  public slots:
    void scalingTime(qreal x);
    void animFinished();


private:
      QGraphicsScene* scene;
      std::vector<QGraphicsPixmapItem*> items;
      int numScheduledScalings;
      int mousePosOriginX,mousePosOriginY;
};

#endif // MAPGRAPHICSVIEW_H

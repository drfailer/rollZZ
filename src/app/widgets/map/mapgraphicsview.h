#ifndef MAPGRAPHICSVIEW_H
#define MAPGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDropEvent>
#include <QWidget>
#include "map.h"
#include "mapgraphicsitem.h"
#include <QMimeData>
#include <QCoreApplication>
#include <QTimeLine>
#include "mapgraphicsscene.h"

class MapGraphicsView: public QGraphicsView
{
  Q_OBJECT
public:
    MapGraphicsView(QWidget* parent);
    qreal getScale() const;
    MapGraphicsScene* getScene() const {return scene;}
    void wheelEvent ( QWheelEvent * event ) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
  public slots:
    void scalingTime(qreal x);
    void animFinished();

private:
  MapGraphicsScene* scene;
  // For Scene position and scaling
  int numScheduledScalings;
  QPointF mousePosOrigin;
  int sceneSizeX,sceneSizeY;
};

#endif // MAPGRAPHICSVIEW_H

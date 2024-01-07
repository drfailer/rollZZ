#ifndef MAPGRAPHICSVIEW_H
#define MAPGRAPHICSVIEW_H


#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDropEvent>
#include <QWidget>
#include "map.h"
#include <QMimeData>
#include <QCoreApplication>

class MapGraphicsView: public QGraphicsView
{
  Q_OBJECT
public:
    MapGraphicsView(QWidget* parent);
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
  signals:
    void dropEventSignal(QDropEvent *event);
    void dragEnterEventSignal(QDragEnterEvent *event) ;
    void dragMoveEventSignal(QDragMoveEvent *event);

private:
      QGraphicsScene* scene;
      std::vector<QGraphicsPixmapItem*> items;
};

#endif // MAPGRAPHICSVIEW_H

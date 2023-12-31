#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QBoxLayout>

class MapWidget: QWidget
{
Q_OBJECT
public:
        MapWidget(QWidget *parent = nullptr);
private:
        QGraphicsView* view;
        QGraphicsScene* scene;
        QBoxLayout* layout;
};

#endif // MAPWIDGET_H

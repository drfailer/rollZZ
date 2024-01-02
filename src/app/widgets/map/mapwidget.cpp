#include "mapwidget.h"
#include <QPushButton>
#include <QGraphicsItem>

MapWidget::MapWidget(QWidget *parent):
    QWidget(parent)
{
    view = new QGraphicsView(this);
    //view->setFixedSize(1000, 800);
    scene = new QGraphicsScene(this);
    layout = new QBoxLayout(QBoxLayout::TopToBottom,this) ;

    QPushButton* b = new QPushButton("coucou",this);
    QPixmap pixmap(":/ressources/tiles/wall");
    pixmap = pixmap.scaled(24,24);
    QGraphicsPixmapItem *item = scene->addPixmap(pixmap);
    item->setPos(264,0);
    QGraphicsPixmapItem *item2 = scene->addPixmap(pixmap);
    item2->setPos(0,264);
    item2->setScale(0.5);
    QGraphicsPixmapItem *item3 = scene->addPixmap(pixmap);


    layout->addWidget(b);
    layout->addWidget(view);
    view->setScene(scene);
}

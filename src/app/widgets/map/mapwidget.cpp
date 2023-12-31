#include "mapwidget.h"
#include <QPushButton>

MapWidget::MapWidget(QWidget *parent):
    QWidget(parent)
{
    view = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    layout = new QBoxLayout(QBoxLayout::TopToBottom,this) ;
    QPushButton* b = new QPushButton("coucou",this);
    QPixmap pixmap("./ressources/test.jpg");
    QGraphicsPixmapItem *item = scene->addPixmap(pixmap);

    layout->addWidget(b);
    layout->addWidget(view);
    view->setScene(scene);
}

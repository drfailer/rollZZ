#include "mapwidget.h"

MapWidget::MapWidget(QWidget *parent, Map map):
    QWidget(parent),
    map(map)
{
    setAcceptDrops(true);
    view = new MapGraphicsView(this);
    connect(view,&MapGraphicsView::dragEnterEventSignal,this,&MapWidget::dragEnterEvent);
    connect(view,&MapGraphicsView::dragMoveEventSignal,this,&MapWidget::dragMoveEvent);
    connect(view,&MapGraphicsView::dropEventSignal,this,&MapWidget::dropEvent);

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    layoutSideMenu = new QBoxLayout(QBoxLayout::LeftToRight,this);
    menu = new QWidget(scrollArea);
    scrollArea->setWidget(menu);

    layoutMenu = new QBoxLayout(QBoxLayout::TopToBottom,menu);

    QPushButton* b = new QPushButton("coucou",menu);

    layoutMenu->addWidget(b);
    layoutSideMenu->addWidget(menu);
    layoutSideMenu->addWidget(view);

    for(MapElement* mapElement: map.getmapElementsUse())
    {
      MapElementWidget* newElement = new MapElementWidget(menu,mapElement);
      layoutMenu->addWidget(newElement);
      connect(newElement,&MapElementWidget::NewCursorLabel,this,[=]()
              {
        labelForCursorDrag->setPixmap(mapElement->getPixMap());
        labelForCursorDrag->resize(mapElement->getPixMap().size());});
    }
    labelForCursorDrag = new QLabel(this);
    labelForCursorDrag->move(-100,-100);
    labelForCursorDrag->setAttribute(Qt::WA_TransparentForMouseEvents);

}

void MapWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("map-element"))
      event->acceptProposedAction();
}

void MapWidget::dragMoveEvent(QDragMoveEvent *event)
{
    // Can't use event->position() in this case
    // Indeed, when the event come from MapGraphicsView
    // It become the position FOR THE VIEW OBJECT
    QPointF position = mapFromGlobal(QCursor::pos());
    if (event->mimeData()->hasFormat("map-element"))
    {
      int sizeX = labelForCursorDrag->pixmap().size().width(),
          sizeY = labelForCursorDrag->pixmap().size().height();
      labelForCursorDrag->move(position.x()-sizeX/2,position.y()-sizeY/2);
      event->acceptProposedAction();
    }

}

void MapWidget::dropEvent(QDropEvent *event)
{
    labelForCursorDrag->clear();
    labelForCursorDrag->move(-100,-100);
    event->accept();
}

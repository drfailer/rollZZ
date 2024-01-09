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

    QPushButton* b = new QPushButton("add new element",menu);
    connect(b,&QPushButton::clicked,this,[&](){
      QStringList filesPath= QFileDialog::getOpenFileNames(this, "Select one or more files to open","/home","Images (*.png *.xpm *.jpg)");
      for(QString filePath: filesPath)
      {
        MapElement* el = map.addElementUse(filePath);
        MapElementWidget* newElement = new MapElementWidget(menu,el);
        layoutMenu->addWidget(newElement);
        connect(newElement,&MapElementWidget::NewCursorLabel,this,[&](MapElement* el)
                {
                  labelForCursorDrag->setVisible(true);
                  labelForCursorDrag->setPixmap(el->getPixMap());
                  labelForCursorDrag->resize(el->getPixMap().size());
                });
      }
    });

    layoutMenu->addWidget(b);
    layoutSideMenu->addWidget(menu);
    layoutSideMenu->addWidget(view);

    labelForCursorDrag = new QLabel(this);
    labelForCursorDrag->move(-100,-100);
    labelForCursorDrag->setVisible(false);
    labelForCursorDrag->setAttribute(Qt::WA_TransparentForMouseEvents);

    for(MapElement* mapElement: map.getmapElementsUse())
    {
      MapElementWidget* newElement = new MapElementWidget(menu,mapElement);
      layoutMenu->addWidget(newElement);
      connect(newElement,&MapElementWidget::NewCursorLabel,this,[&](MapElement* mapElement)
              {
                labelForCursorDrag->setVisible(true);
                labelForCursorDrag->setPixmap(mapElement->getPixMap());
                labelForCursorDrag->resize(mapElement->getPixMap().size());});

    }
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
    labelForCursorDrag->setVisible(false);
    event->accept();
}

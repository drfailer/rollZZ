#include "mapwidget.h"

MapWidget::MapWidget(QWidget *parent, Map* map):
    QWidget(parent),
    map(map)
{
    setAcceptDrops(true);
    view = new MapGraphicsView(this);
    connect(view->getScene(),&MapGraphicsScene::dragEnterEventSignal,this,&MapWidget::dragEnterEvent);
    connect(view->getScene(),&MapGraphicsScene::dragMoveEventSignal,this,&MapWidget::dragMoveEvent);
    connect(view->getScene(),&MapGraphicsScene::dropEventSignal,this,&MapWidget::drop);

    layoutSideMenu = new QBoxLayout(QBoxLayout::LeftToRight,this);

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    menu = new QWidget(scrollArea);
    menuItemOnMap = new QWidget(this);
    layoutMenuItemOnMap = new QBoxLayout(QBoxLayout::TopToBottom,menuItemOnMap);
    scrollArea->setWidget(menu);

    layoutMenu = new QBoxLayout(QBoxLayout::TopToBottom,menu);

    QPushButton* b = new QPushButton("add new element",menu);
    connect(b,&QPushButton::clicked,this,[=](){
      QStringList filesPath= QFileDialog::getOpenFileNames(this, "Select one or more files to open","/home","Images (*.png *.xpm *.jpg)");
      for(QString& filePath: filesPath)
      {
        QString name = filePath.mid(filePath.lastIndexOf('/')+1);
        QString newFilePath = QDir::homePath() + QString("/.local/ressources/") + name;

        if (QFile::exists(newFilePath))
          QFile::remove(newFilePath);

        QFile::copy(filePath,newFilePath);

        MapElement* el = map->addElementUse(newFilePath,name);
        el->RescalePixMap(PIXMAP_MENU_SIZE,PIXMAP_MENU_SIZE);
        MapElementWidget* newElement = new MapElementWidget(menu,el);
        layoutMenu->addWidget(newElement);
        connect(newElement,&MapElementWidget::NewCursorLabel,this,[&](MapElement* el)
                {
                  QPixmap labelPixMap = el->getPixMap();
                  labelPixMap = labelPixMap.scaled(labelPixMap.size()*view->getScale());
                  labelForCursorDrag->setVisible(true);
                  labelForCursorDrag->setPixmap(labelPixMap);
                  labelForCursorDrag->resize(labelPixMap.size());
                });
      }
    });

    layoutMenu->addWidget(b);
    layoutSideMenu->addWidget(menu);
    layoutSideMenu->addWidget(view);
    layoutSideMenu->addWidget(menuItemOnMap);

    labelForCursorDrag = new QLabel(this);
    labelForCursorDrag->move(-100,-100);
    labelForCursorDrag->setVisible(false);
    labelForCursorDrag->setAttribute(Qt::WA_TransparentForMouseEvents);

    for(MapElement* mapElement: map->getmapElementsUse())
    {
      MapElementWidget* newElement = new MapElementWidget(menu,mapElement);
      layoutMenu->addWidget(newElement);

      //create a function since I repeat this 2 times;
      connect(newElement,&MapElementWidget::NewCursorLabel,this,[&](MapElement* el)
              {
                QPixmap labelPixMap = el->getPixMap();
                labelPixMap = labelPixMap.scaled(labelPixMap.size()*view->getScale());
                labelForCursorDrag->setVisible(true);
                labelForCursorDrag->setPixmap(labelPixMap);
                labelForCursorDrag->resize(labelPixMap.size());
              });
    }
}

void MapWidget::dragEnterEvent(QDragEnterEvent *event)
{    if (event->mimeData()->hasFormat("map-element"))
      event->acceptProposedAction();}

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
    drop(event,nullptr);
}

void MapWidget::drop(QDropEvent *event, MapGraphicsItem* itemDrop)
{
    labelForCursorDrag->clear();
    labelForCursorDrag->move(-100,-100);
    labelForCursorDrag->setVisible(false);
    event->accept();

    if(itemDrop)
    {
      QPushButton* temp = new QPushButton(itemDrop->getMapElement()->getName(),menuItemOnMap);
      connect (temp,&QPushButton::clicked,this,[=](){itemDrop->setSelected(true); view->update();});
      layoutMenuItemOnMap->addWidget(temp);
    }
}

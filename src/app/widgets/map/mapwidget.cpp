#include "mapwidget.h"

MapWidget::MapWidget(QWidget *parent, Map* map): QWidget(parent),map(map)
{
  setAcceptDrops(true);
  sideMenu = new QWidget(this);
  menu = new QWidget(this);
  layoutMenu = new QVBoxLayout(menu);
  layoutGlobal = new QVBoxLayout(this);
  layoutGlobal->addWidget(menu);
  layoutGlobal->addWidget(sideMenu);

  view = new MapGraphicsView(sideMenu);
  connect(view->getScene(),&MapGraphicsScene::dragEnterEventSignal,this,&MapWidget::dragEnterEvent);
  connect(view->getScene(),&MapGraphicsScene::dragMoveEventSignal,this,&MapWidget::dragMoveEvent);
  connect(view->getScene(),&MapGraphicsScene::dropEventSignal,this,&MapWidget::drop);

  menuItemOnMap = new MapScrollArea(sideMenu);
  menuMapElementSelection = new QWidget(sideMenu);
  QPushButton* addButton = new QPushButton("add new element",menuMapElementSelection);
  scrollAreaMapElementSelection = new MapScrollArea(menuMapElementSelection);
  scrollAreaMapElementSelection->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
  layerSelection = new LayerSelection(menuMapElementSelection);
  connect(layerSelection,&LayerSelection::changeLayer,this,[&](int i){view->getScene()->setActualZValue(i);});

  layoutMenuMapElement = new QVBoxLayout(menuMapElementSelection);
  layoutMenuMapElement->setAlignment(Qt::AlignTop);
  layoutMenuMapElement->addWidget(addButton);
  layoutMenuMapElement->addWidget(layerSelection);
  layoutMenuMapElement->addWidget(scrollAreaMapElementSelection);

  layoutSideMenu = new QBoxLayout(QBoxLayout::LeftToRight,sideMenu);
  layoutSideMenu->addWidget(menuMapElementSelection);
  layoutSideMenu->addWidget(view);
  layoutSideMenu->addWidget(menuItemOnMap);

  QPushButton* buttonSave = new QPushButton("save",menu);
  layoutMenu->addWidget(buttonSave);
  connect(buttonSave,&QPushButton::pressed,this,&MapWidget::saveMap);

  labelForCursorDrag = new QLabel(this);
  labelForCursorDrag->move(-100,-100);
  labelForCursorDrag->setVisible(false);
  labelForCursorDrag->setAttribute(Qt::WA_TransparentForMouseEvents);

  auto lambdaLabel = [&](MapElement* el)
  {
    QPixmap labelPixMap = el->getOriginalPixMap();
    labelPixMap = labelPixMap.scaled(labelPixMap.size()*view->getScale());
    labelForCursorDrag->setVisible(true);
    labelForCursorDrag->setPixmap(labelPixMap);
    labelForCursorDrag->resize(labelPixMap.size());
  };

  connect(addButton,&QPushButton::clicked,this,[=](){
    QStringList filesPath= QFileDialog::getOpenFileNames(this, "Select one or more files to open","/home","Images (*.png *.xpm *.jpg *.jpeg)");
    for(QString& filePath: filesPath)
    {
      QString name = filePath.mid(filePath.lastIndexOf('/')+1,filePath.lastIndexOf('.'));
      QString newFilePath = QDir::homePath() + QString("/.local/resources/") + name;

      if (QFile::exists(newFilePath))
        QFile::remove(newFilePath);
      QFile::copy(filePath,newFilePath);

      MapElement* el = map->addElementUse(newFilePath,name);
      MapElementWidget* newElement = new MapElementWidget(el,scrollAreaMapElementSelection);
      scrollAreaMapElementSelection->addContent(newElement);
      connect(newElement,&MapElementWidget::NewCursorLabel,this,lambdaLabel);
    }
  });

  loading = true;
  map->load(QDir::homePath() + QString("/.local/resources/testMap.txt"));
  for(MapElement* mapElement: map->getmapElementsUse())
  {
    MapElementWidget* newElement = new MapElementWidget(mapElement,scrollAreaMapElementSelection);
    scrollAreaMapElementSelection->addContent(newElement);

    connect(newElement,&MapElementWidget::NewCursorLabel,this,lambdaLabel);
  }
  for(MapElement* mapElement: map->getMap())
  {
    view->getScene()->insertNewGraphicsElement(mapElement);
  }
  loading = false;
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

void MapWidget::dropEvent(QDropEvent *)
{
    drop(nullptr);
}

void MapWidget::drop(MapGraphicsItem* itemDrop)
{
    labelForCursorDrag->clear();
    labelForCursorDrag->move(-100,-100);
    labelForCursorDrag->setVisible(false);
    if(itemDrop)
      addNewItem(itemDrop);

}

void MapWidget::addNewItem(MapGraphicsItem* itemDrop)
{
    QPushButton* temp = new QPushButton(itemDrop->getMapElement()->getName(),menuItemOnMap);
    connect (temp,&QPushButton::clicked,this,[=](){itemDrop->setSelected(true);});
    connect (itemDrop,&MapGraphicsItem::deleteSignal,this,[=](){menuItemOnMap->removeContent(temp);map->removeElementOnMap(itemDrop->getMapElement()); delete temp;});
    menuItemOnMap->addContent(temp);
    if (!loading)
      map->addElementOnMap(itemDrop->getMapElement());
}

void MapWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Delete)
      view->getScene()->deleteSelected();
}

void MapWidget::saveMap()
{
    map->save(QDir::homePath() + QString("/.local/resources/testMap.txt"));
}

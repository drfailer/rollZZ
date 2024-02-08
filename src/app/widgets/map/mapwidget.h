#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QFileDialog>
#include "map.h"
#include "mapelementwidget.h"
#include "mapgraphicsview.h"
#include "mapscrollarea.h"
#include "layerselection.h"

#define PIXMAP_MENU_SIZE 128

/*
 * TODO
 * - clean all code
 * - save also position and rotation of mapElement
 * - generalize save and load
 **/

class MapWidget: public QWidget
{
  Q_OBJECT
public:
    MapWidget(QWidget *parent = nullptr, Map* map = {});
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void addNewItem(MapGraphicsItem* itemDrop,bool isNewElement);
    ~MapWidget() {/*TODO*/}
  public slots:
    void drop(MapGraphicsItem* dropItem,bool isNewElement);
    void saveMap();
  private:
    MapGraphicsView* view;
    QWidget* menu;
    QWidget* sideMenu;
    QVBoxLayout* layoutGlobal;
    QVBoxLayout* layoutMenu;
    QBoxLayout* layoutSideMenu;
    Map* map;
    QLabel* labelForCursorDrag;
    QWidget* menuMapElementSelection;
    QVBoxLayout* layoutMenuMapElement;
    MapScrollArea* scrollAreaMapElementSelection;
    MapScrollArea* menuItemOnMap;
    LayerSelection* layerSelection;

};

#endif // MAPWIDGET_H

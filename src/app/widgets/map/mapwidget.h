#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QFileDialog>
#include <QTabWidget>
#include "map.h"
#include "mapelementwidget.h"
#include "mapgraphicsview.h"
#include "mapscrollarea.h"
#include "layerselection.h"
#include "chat.h"


/*
 * TODO
 * - generalize save and load
 **/

class MapWidget: public QWidget
{
  Q_OBJECT
public:
    MapWidget(QWidget *parent = nullptr, Map* map = {});
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *) override;
    void keyPressEvent(QKeyEvent *event) override;
    void addNewItem(MapGraphicsItem* itemDrop);
    ~MapWidget() {/*TODO*/}
  public slots:
    void drop(MapGraphicsItem* dropItem);
    void saveMap();

  private:
    QTabWidget* tabRight;
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
    Chat* chat;
    LayerSelection* layerSelection;
    bool loading;
};

#endif // MAPWIDGET_H

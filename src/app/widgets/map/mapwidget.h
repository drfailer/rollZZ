#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QFileDialog>
#include "gamecs/gamecs.h"
#include <QTabWidget>
#include "map.h"
#include "mapelementwidget.h"
#include "mapgraphicsview.h"
#include "mapscrollarea.h"
#include "layerselection.h"
#include "chat.h"
#include "User.h"


/*
 * TODO
 * - generalize save and load
 **/

class MapWidget: public QWidget
{
  Q_OBJECT
public:
  MapWidget(Map* map, QWidget *parent = nullptr);
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
    QWidget* sideMenu;
    QVBoxLayout* layoutGlobal;
    QBoxLayout* layoutSideMenu;
    Map* map;
    QLabel* labelForCursorDrag;
    QWidget* menuMapElementSelection;
    QVBoxLayout* layoutMenuMapElement;
    MapScrollArea* scrollAreaMapElementSelection;
    MapScrollArea* menuItemOnMap;
    Chat* chat;
    User* user;
    LayerSelection* layerSelection;
    bool loading;

    GameCS::GameCS *cs = nullptr;
};

#endif // MAPWIDGET_H

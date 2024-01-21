#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QFileDialog>
#include "map.h"
#include "mapelementwidget.h"
#include "mapgraphicsview.h"

#define PIXMAP_MENU_SIZE 128

/*
 *
 * TODO
 * - Layer option
 * - Menu to see existing item on the map (to select them more easily)
 * - function for menu item used
 * - Create a class for menu (widget, layout and scrollArea)
 * - modify the scroll area so we can see the bottom element
 * - clean all code
 * - Take the original image when drop on map (not the menu one)
 * => reload the image (not opti if lot of them, or other attribute pixmap in mapElement)
 **/

class MapWidget: public QWidget
{
  Q_OBJECT
public:
    MapWidget(QWidget *parent = nullptr, Map* map = {});
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    ~MapWidget() {/*TODO*/}
  public slots:
    void drop(QDropEvent *event, MapGraphicsItem* dropItem);
private:
        MapGraphicsView* view;
        QBoxLayout* layoutSideMenu;
        QBoxLayout* layoutMenu;
        QBoxLayout* layoutMenuItemOnMap;
        QScrollArea* scrollArea;
        QWidget* menu;
        QWidget* menuItemOnMap;
        Map* map;
        QLabel* labelForCursorDrag;
};

#endif // MAPWIDGET_H

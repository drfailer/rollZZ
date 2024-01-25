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

#define PIXMAP_MENU_SIZE 128

/*
 *
 * TODO
 * - Layer option
 * - clean all code
 * - Take the original image when drop on map (not the menu one)
 * => reload the image (not opti if lot of them, or other attribute pixmap in mapElement)
 * - item outside map bug
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
        Map* map;
        QLabel* labelForCursorDrag;
        MapScrollArea* menuMapElementSelection;
        MapScrollArea* menuItemOnMap;
};

#endif // MAPWIDGET_H

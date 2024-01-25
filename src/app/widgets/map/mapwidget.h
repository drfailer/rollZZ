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
    ~MapWidget() {/*TODO*/}
  public slots:
    void drop(QDropEvent *event, MapGraphicsItem* dropItem);
private:
        MapGraphicsView* view;
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

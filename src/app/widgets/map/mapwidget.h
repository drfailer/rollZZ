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
 * - attribute for scene size and MapElement size (or else they are just to big)
 * - Layer option
 * - Move/resize/rotate/delete items on the graphics scene
 *
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
private:
        MapGraphicsView* view;
        QBoxLayout* layoutSideMenu;
        QBoxLayout* layoutMenu;
        QScrollArea* scrollArea;
        QWidget* menu;
        Map* map;
        QLabel* labelForCursorDrag;
};

#endif // MAPWIDGET_H

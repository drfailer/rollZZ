#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include "map.h"
#include "mapelementwidget.h"
#include "mapgraphicsview.h"

class MapWidget: public QWidget
{
  Q_OBJECT
public:
    MapWidget(QWidget *parent = nullptr, Map map = {});
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
        Map map;
        QLabel* labelForCursorDrag;
};

#endif // MAPWIDGET_H

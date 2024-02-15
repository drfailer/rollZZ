#ifndef mapElementWIDGET_H
#define mapElementWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>
#include "mapelement.h"
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>

class MapElementWidget: public QWidget
{
    Q_OBJECT
    public:
        MapElementWidget(MapElement* mapElement,QWidget *parent = nullptr);
        void mousePressEvent(QMouseEvent *event) override;
        ~MapElementWidget() {/*TODO*/}
      signals:
        void NewCursorLabel(MapElement*);
    private:
            QLabel* label;
            QLabel* labelName;
            QBoxLayout* layout;
            MapElement* mapElementToRepresent;
};

#endif // mapElementWIDGET_H

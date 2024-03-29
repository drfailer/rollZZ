#include "mapelementwidget.h"

MapElementWidget::MapElementWidget(MapElement* mapElementToRepresent,QWidget* parent):
QWidget(parent),
mapElementToRepresent(mapElementToRepresent)
{
    layout = new QBoxLayout(QBoxLayout::TopToBottom,this);
    label = new QLabel(this);
    label->setPixmap(mapElementToRepresent->getPreviewPixMap());
    layout->addWidget(label);
    labelName = new QLabel(this);
    labelName->setText(mapElementToRepresent->getName());
    layout->addWidget(labelName);
    layout->setSizeConstraint(QLayout::SetFixedSize);

}

void MapElementWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;
        QByteArray byteArray;
        QDataStream outStream(&byteArray, QIODevice::WriteOnly);
        outStream << mapElementToRepresent;

        mimeData->setData("map-element",byteArray);
        drag->setMimeData(mimeData);
        emit NewCursorLabel(mapElementToRepresent);
        Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
        event->accept();
    }
}


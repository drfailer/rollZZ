#include "mapscrollarea.h"

MapScrollArea::MapScrollArea(QWidget* parent): QScrollArea(parent)
{
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setWidgetResizable(true);
  content = new QWidget(this);
  layout= new QVBoxLayout(content);
  layout->setAlignment(Qt::AlignTop);
  setWidget(content);
}

void MapScrollArea::addContent(QWidget * el)
{
  layout->addWidget(el);
}

void MapScrollArea::removeContent(QWidget * el)
{
  layout->removeWidget(el);
}

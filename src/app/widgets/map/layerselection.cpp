#include "layerselection.h"

LayerSelection::LayerSelection(QWidget* widget):QWidget(widget)
{
  layout = new QHBoxLayout(this);
  layout->setAlignment(Qt::AlignLeft);
  buttons = QVector<QPushButton*>(4);

  for(int i = 0; i < 4;i++)
  {
    QPushButton* temp = new QPushButton(std::to_string(i-1).c_str() ,this);
    buttons.push_back(temp);
    layout->addWidget(temp);
    connect(temp,&QPushButton::clicked,this,[i,this](){ emit changeLayer(i-1);});
  }
}

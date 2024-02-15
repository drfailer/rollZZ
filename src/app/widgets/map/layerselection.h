#ifndef LAYERSELECTION_H
#define LAYERSELECTION_H

#include <QPushButton>
#include <QHBoxLayout>

class LayerSelection: public QWidget
{
Q_OBJECT
public:
  LayerSelection(QWidget* parent = nullptr);
signals:
  void changeLayer(int i);
private:
  QHBoxLayout* layout;
  QVector<QPushButton*> buttons;
};

#endif // LAYERSELECTION_H

#ifndef MAPSCROLLAREA_H
#define MAPSCROLLAREA_H
#include <QScrollArea>
#include <QVBoxLayout>

class MapScrollArea : public QScrollArea
{
Q_OBJECT
public:
  MapScrollArea(QWidget* parent = nullptr);
  void addContent(QWidget *);
  void removeContent(QWidget *);

private:
  QWidget* content;
  QVBoxLayout* layout;
};

#endif // MAPSCROLLAREA_H

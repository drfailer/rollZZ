#ifndef mapElementS_H
#define mapElementS_H

#include  <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <QGraphicsView>
#include <QGraphicsItem>


// No verification if the file overwrite
class MapElement
{
public:
  MapElement(QString filePath=":ressources/mapElements/wall");
  MapElement(QString filePath,QString name);
  QPixmap getPixMap() const {return pixMap;}
  QString getName() const {return name;}
  QString getFilePath() const {return filePath;}
  void setPixMap(QPixmap map) {pixMap = map;}
  void setName(QString name) {filePath = name;}
  void setFilePath(QString filePath) {filePath = filePath;}
  QSize getImageSize()const {return imageSize;}
  QSize getPixMapSize()const {return pixMapSize;}
  void RescalePixMap(int maxX,int maxY);
private:
  //need to be safe
  QString filePath;
  QString name;
  QSize pixMapSize;

  // can be retreive from the previous information
  QSize imageSize;
  QPixmap pixMap;
};

QDataStream &operator>>(QDataStream &stream, MapElement* el);
QDataStream &operator<<(QDataStream &stream, const MapElement* el);
#endif // mapElementS_H

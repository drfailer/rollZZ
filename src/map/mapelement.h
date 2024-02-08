#ifndef mapElementS_H
#define mapElementS_H

#include  <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <QGraphicsView>
#include <QGraphicsItem>

#include "serializable.hpp"
#include "serializer.hpp"
#include "qtconvertor.h"

// No verification if the file overwrite
class MapElement
{
  SERIALIZABLE_WITH_CONVERTOR(QtConvertor,QString,QString,int,int)
public:
  MapElement(QString filePath="");
  MapElement(QString filePath,QString name);
  MapElement(QString _filePath,QString _name,int posX,int posY);
  QPixmap getPreviewPixMap() const {return previewPixMap;}
  QPixmap getOriginalPixMap() const {return originalPixMap;}
  QString getName() const {return name;}
  QString getFilePath() const {return filePath;}
  QPointF getPos() {return QPointF(posX,posY);}
  void setPreviewPixMap(QPixmap map) {this->previewPixMap = map;}
  void setOriginalPixMap(QPixmap map) {this->originalPixMap = map;}
  void setName(QString name) {this->name = name;}
  void setFilePath(QString filePath) {this->filePath = filePath;}
  void setPos(int x,int y) {posX=x;posY=y;}
  QSize getImageSize()const {return imageSize;}
  void RescalePixMap(int maxX,int maxY);
  void updateImage();

  void load(const QString& filePath);
  void save(const QString& filePath);

private:
  //need to be save
  QString filePath;
  QString name;
  int posX,posY;

  // can be retreive from the previous information
  QSize imageSize;
  QPixmap previewPixMap;
  QPixmap originalPixMap;
};

QDataStream &operator>>(QDataStream &stream, MapElement* el);
QDataStream &operator<<(QDataStream &stream, const MapElement* el);
#endif // mapElementS_H

#ifndef mapElementS_H
#define mapElementS_H

#include  <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QFile>

#include "serializable.hpp"
#include "serializer.hpp"
#include "tools/qtconvertor.h"
#include "config.h"

#define PREVIEW_SIZE 64

// No verification if the file overwrite
class MapElement
{
  SERIALIZABLE_WITH_CONVERTOR(QtConvertor,QString,QString,int,int,float,float,float,int)
public:
  MapElement(QString filePath="");
  MapElement(QString filePath,QString name);
  MapElement(QString _filePath,QString _name,int posX,int posY, float rotation,float  sizeX, float sizeY, int layer);

  QPixmap getPreviewPixMap() const {return previewPixMap;}
  QPixmap getOriginalPixMap() const {return originalPixMap;}
  QString getName() const {return name;}
  QString getFilePath() const {return filePath;}
  QPointF getPos() {return QPointF(posX,posY);}
  QSizeF getSize() {return QSizeF(sizeX,sizeY);}
  float getRotation() {return rotation;}
  int getLayer() {return layer;}
  QSize getImageSize()const {return imageSize;}

  void setPreviewPixMap(QPixmap map) {this->previewPixMap = map;}
  void setOriginalPixMap(QPixmap map) {this->originalPixMap = map;}
  void setName(QString name) {this->name = name;}
  void setFilePath(QString filePath) {this->filePath = filePath;}
  void setPos(int x,int y) {posX=x;posY=y;}
  void setRotate(float r){rotation = r;}
  void setSize(float x,float y) { sizeX = x; sizeY = y;}
  void setLayer(int l){layer=l;}

  void RescalePixMap(int maxX,int maxY);
  void updateImage();

private:
  //need to be save
  QString filePath;
  QString name;
  int posX,posY;
  float rotation;
  float sizeX,sizeY;
  int layer;

  // can be retreive from the previous information
  QSize imageSize;
  QPixmap previewPixMap;
  QPixmap originalPixMap;
};

QDataStream &operator>>(QDataStream &stream, MapElement* el);
QDataStream &operator<<(QDataStream &stream, const MapElement* el);

#endif // mapElementS_H

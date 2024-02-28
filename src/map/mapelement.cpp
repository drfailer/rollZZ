#include "mapelement.h"


MapElement::MapElement(QString _filePath,QString _name,int _posX,int _posY,
                       float _rotation,float _sizeX,float _sizeY,int _layer):
SERIALIZER(filePath, name, posX, posY, rotation, sizeX, sizeY, layer),filePath(_filePath),
name(_name),posX(_posX),posY(_posY),rotation(_rotation),sizeX(_sizeX),sizeY(_sizeY),layer(_layer)
{
  updateImage();
}

MapElement::MapElement(QString _filePath,QString _name): MapElement(_filePath,_name,-1,-1,0,0,0,0)
{}

MapElement::MapElement(QString _filePath): MapElement(_filePath,_filePath.mid(_filePath.lastIndexOf('/')+1))
{}

void MapElement::RescalePixMap(int maxX,int maxY)
{
  QSize pixMapSize;
  float ratioX = maxX/float(imageSize.width());
  float ratioY = maxY/float(imageSize.height());
  if(ratioX<ratioY)
    pixMapSize = QSize(imageSize.width()*ratioY,maxY);
  else
    pixMapSize = QSize(maxX,imageSize.height()*ratioX);

  previewPixMap = originalPixMap.scaled(pixMapSize);
}

QDataStream &operator<<(QDataStream &stream, const MapElement* el) {
  stream << el->getName();
  stream << el->getFilePath();
  return stream;
}

QDataStream &operator>>(QDataStream &stream, MapElement* el)
{
  QString name;
  QPixmap map;
  QString filePath;
  stream >> name;
  stream >> filePath;
  el->setName(name);
  el->setFilePath(filePath);
  el->updateImage();
  return stream;
}

void MapElement::updateImage()
{
  originalPixMap = previewPixMap = QPixmap(filePath);
  RescalePixMap(PREVIEW_SIZE,PREVIEW_SIZE);
  imageSize = originalPixMap.size();

  if(sizeX == 0)
  {
    sizeX = imageSize.width();
    sizeY = imageSize.height();
  }
}

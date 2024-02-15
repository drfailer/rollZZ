#include "mapelement.h"


MapElement::MapElement(QString _filePath,QString _name,int _posX,int _posY): SERIALIZER(filePath, name, posX, posY),filePath(_filePath),name(_name),posX(_posX),posY(_posY)
{
  updateImage();
}

MapElement::MapElement(QString _filePath,QString _name): MapElement(_filePath,_name,-1,-1)
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

    previewPixMap = previewPixMap.scaled(pixMapSize);
}

QDataStream &operator<<(QDataStream &stream, const MapElement* el) {
    stream << el->getOriginalPixMap();
    stream << el->getName();
    stream << el->getFilePath();
    return stream;
}

QDataStream &operator>>(QDataStream &stream, MapElement* el)
{
    QString name;
    QPixmap map;
    QString filePath;
    stream >> map;
    stream >> name;
    stream >> filePath;
    el->setOriginalPixMap(map);
    el->setName(name);
    el->setFilePath(filePath);
    return stream;
}

void MapElement::load(const QString& fileName) {
    //clearParts();
    deserializeFile(fileName.toStdString());
    updateImage();
}
void MapElement::save(const QString& fileName) {
    serializeFile(fileName.toStdString());
}

void MapElement::updateImage()
{
    originalPixMap = previewPixMap = QPixmap(filePath);
    imageSize = originalPixMap.size();
}

#include "mapelement.h"

MapElement::MapElement(QString filePath):filePath(filePath),name(filePath.mid(filePath.lastIndexOf('/')+1))
{
    originalPixMap = previewPixMap = QPixmap(filePath);
    imageSize = previewPixMap.size();
}

MapElement::MapElement(QString filePath,QString name):filePath(filePath),name(name)
{
    originalPixMap = previewPixMap = QPixmap(filePath);
    imageSize = previewPixMap.size();
}

void MapElement::RescalePixMap(int maxX,int maxY)
{
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
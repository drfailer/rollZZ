#include "mapelement.h"

MapElement::MapElement(QString filePath):filePath(filePath),name(filePath.mid(filePath.lastIndexOf('/')))
{
    pixMap = QPixmap(filePath);
    imageSize = pixMap.size();
}

MapElement::MapElement(QString filePath,QString name):filePath(filePath),name(name)
{
    pixMap = QPixmap(filePath);
    imageSize = pixMap.size();
}

void MapElement::RescalePixMap(int maxX,int maxY)
{
    float ratioX = maxX/float(imageSize.width());
    float ratioY = maxY/float(imageSize.height());
    if(ratioX<ratioY)
      pixMapSize = QSize(imageSize.width()*ratioY,maxY);
    else
      pixMapSize = QSize(maxX,imageSize.height()*ratioX);

    pixMap = pixMap.scaled(pixMapSize);
}

QDataStream &operator<<(QDataStream &stream, const MapElement* el) {
    stream << el->getPixMap();
    stream << el->getFilePath();
    return stream;
}

QDataStream &operator>>(QDataStream &stream, MapElement* el)
{
    QString name;
    QPixmap map;

    stream >> map;
    stream >> name;
    el->setPixMap(map);
    el->setFilePath(name);
    return stream;
}

#include "mapelement.h"

MapElement::MapElement(QString filePath, int x, int y):filePath(filePath),ratio({x,y})
{
    pixMap = QPixmap(filePath);
    pixMap = pixMap.scaled(64,64);
}

QDataStream &operator<<(QDataStream &stream, const MapElement* el) {
    stream << el->getPixMap();
    stream << el->getName();
    return stream;
}

QDataStream &operator>>(QDataStream &stream, MapElement* el)
{
    QString name;
    QPixmap map;

    stream >> map;
    stream >> name;
    el->setPixMap(map);
    el->setName(name);
    return stream;
}

#ifndef mapElementS_H
#define mapElementS_H

#include  <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <QGraphicsView>
#include <QGraphicsItem>

class MapElement
{
public:
    MapElement(QString filePath=":ressources/mapElements/wall", int x = 1, int y = 1);
    QPixmap getPixMap() const {return pixMap;}
    QString getName() const {return filePath;}
    void setPixMap(QPixmap map) {pixMap = map;}
    void setName(QString name) {filePath = name;}
private:
 //need to be safe
 QString filePath;

 // can be retreive from the previous information
 std::pair<int,int> ratio;
 QPixmap pixMap;
};

QDataStream &operator>>(QDataStream &stream, MapElement* el);
QDataStream &operator<<(QDataStream &stream, const MapElement* el);

#endif // mapElementS_H

#ifndef NAME_H
#define NAME_H

#include <QString>
#include <serializer.hpp>
#include <qtconvertor.h>

class Name
{
    SERIALIZABLE_WITH_CONVERTOR(QtConvertor,QString)
  public:
    Name():SERIALIZER(name){}
    Name(QString _name):SERIALIZER(name),name(_name){}
    QString getName() const {return name;}
    void setName(QString s) {name = s;}
  private:
    QString name;
};

#endif // NAME_H

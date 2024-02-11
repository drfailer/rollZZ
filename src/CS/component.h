#ifndef CS_COMPONENT_H
#define CS_COMPONENT_H

#include <QString>
#include "serializer.hpp"
#include "qtconvertor.h"

namespace CS {

class Component {
    __SERIALIZABLE__(QtConvertor, POLYMORPHIC_FN_IMPL, QString);
  public:
    Component(const QString &title = "title");
    virtual ~Component() = 0;

    /* accessors **************************************************************/
    QString getTitle() const { return title; }
    void setTitle(const QString &newTitle) { title = newTitle; }

  private:
    QString title;
};

} // end namespace CS

#endif // COMPONENT_H

#ifndef CS_SECTION_H
#define CS_SECTION_H

#include "component.h"
#include "serializer.hpp"
#include "componentconvertor.h"
#include <QList>
#include <QString>

// TODO: move elsewhere

namespace CS {

class Section {
    SERIALIZABLE_WITH_CONVERTOR(ComponentConvertor, QString,
                                QList<Component *>);

  public:
    Section(const QString &title = "name");
    ~Section();
    /* methods ****************************************************************/
    void addComponent(Component *);
    void removeComponent(Component *);
    const QList<Component *> &getComponents() const { return components; }
    // TODO: move components

    /* accessors **************************************************************/
    QString getTitle() const { return title; }
    void setTitle(const QString &newTitle) { title = newTitle; }

  private:
    QString title;
    QList<Component *> components;
};

} // end namespace CS

#endif // SECTION_H

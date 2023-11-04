#ifndef SECTION_H
#define SECTION_H

#include <QList>
#include <QString>

namespace CS {

class Component;

class Section
{
public:
    Section(const QString& title);
    ~Section();
    /* methods *************************************/
    void addComponent(Component*);
    // TODO: move components

    QString getTitle() const { return title; }
    void setTitle(const QString &newTitle) { title = newTitle; }

private:
    QString title;
    QList<Component*> components;
};

} // end namespace CS

#endif // SECTION_H

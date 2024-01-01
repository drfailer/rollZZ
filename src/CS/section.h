#ifndef CS_SECTION_H
#define CS_SECTION_H

#include <QList>
#include <QString>

namespace CS {

class Component;

class Section
{
public:
    Section(const QString& title);
    ~Section();
    /* methods *****************************************************************/
    void addComponent(Component*);
    void removeComponent(Component*);
    const QList<Component*>& getComponents() const { return components; }
    // TODO: move components

    /* accessors ***************************************************************/
    QString getTitle() const { return title; }
    void setTitle(const QString &newTitle) { title = newTitle; }

private:
    QString title;
    QList<Component*> components;
};

} // end namespace CS

#endif // SECTION_H

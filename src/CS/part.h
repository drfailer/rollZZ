#ifndef CS_PART_H
#define CS_PART_H

#include "section.h"

#include <QList>
#include <QString>

namespace CS {
class Part
{
public:
    Part(const QString& name = "name");
    ~Part();

    /* accessors ***************************************************************/
    void setName(QString name) { this->name = name; }
    QString getName() const { return name; }
    void addSection(CS::Section* section);
    void removeSection(CS::Section* section);
    void removeSection(int index);

private:
    QString name;
    QList<Section*> sections;
};
}

#endif // PART_H

#ifndef CS_PART_H
#define CS_PART_H

#include "qtconvertor.h"
#include "section.h"

#include <QList>
#include <QString>

namespace CS {
class Part {
    SERIALIZABLE_WITH_CONVERTOR(QtConvertor, QString, QList<Section*>);
  public:
    Part(const QString &name = "name");
    ~Part();

    /* accessors
     * ***************************************************************/
    void setName(QString name) { this->name = name; }
    QString getName() const { return name; }
    void addSection(CS::Section *section);
    void removeSection(CS::Section *section);
    void removeSection(int index);
    const QList<Section *> &getSections() const { return sections; }

  private:
    QString name;
    QList<Section *> sections;
};
} // namespace CS

#endif // PART_H

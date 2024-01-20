#ifndef CS_CS_H
#define CS_CS_H

#include "part.h"
#include "serializable.hpp"
#include "qtconvertor.h"

#include <QList>

namespace CS {

class CS {
    SERIALIZABLE_WITH_CONVERTOR(QtConvertor, QString, QList<Part *>);

  public:
    CS() : SERIALIZER(characterName, parts) {}
    ~CS();

    /* methods ****************************************************************/
    void addPart(Part *part) { parts.push_back(part); }
    const QList<Part *> &getParts() const { return parts; }
    void clearParts();
    // TODO: add a way to move parts
    void load(const QString& fileName) {
        clearParts();
        deserializeFile(fileName.toStdString());
    }
    void save(const QString& fileName) {
        serializeFile(fileName.toStdString());
    }

    /* accessors **************************************************************/
    void setCharacterName(QString characterName) { this->characterName = characterName; }
    QString getCharacterName() const { return characterName; }

  private:
    QString characterName;
    QList<Part *> parts;
};

} // namespace CS

#endif // CS_H

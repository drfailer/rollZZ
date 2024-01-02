#ifndef CS_CARACTERISTIC_H
#define CS_CARACTERISTIC_H

#include "dice.h"
#include "qtconvertor.h"
#include "serializable.hpp"

#include <QString>

namespace CS {

class Caracteristic {
    SERIALIZABLE_WITH_CONVERTOR(QtConvertor, QString, QString, int, bool, Dice);
  public:
    Caracteristic(const QString &name = "name", const QString &statName = "statname",
                  Dice dice = Dice(), int checked = false);
    Caracteristic(const Caracteristic& other): Caracteristic(other.name,
            other.linkedStatName, other.dice, other.checked) { }
    int roll() const;

    /* accessors **************************************************************/
    QString getName() const { return name; }
    void setName(const QString &newName) { name = newName; }
    int getBonus() const { return bonus; }
    void setBonus(int newBonus) { bonus = newBonus; }
    int getChecked() const { return checked; }
    void setChecked(int newChecked) { checked = newChecked; }
    Dice getDice() const { return dice; }
    void setDice(const Dice &newDice) { dice = newDice; }

    Caracteristic operator=(const Caracteristic& other) {
        name = other.name;
        linkedStatName = other.linkedStatName;
        bonus = other.bonus;
        checked = other.checked;
        dice = other.dice;
        return *this;
    }

  private:
    QString name;
    QString linkedStatName;
    int bonus;
    bool checked;
    Dice dice;
};

} // end namespace CS

#endif // CARACTERISTIC_H

#ifndef CS_DICE_H
#define CS_DICE_H

#include "serializer.hpp"

class Dice {
    SERIALIZABLE(int, int);
  public:
    Dice(int faces = 20, int number = 1);
    Dice(const Dice &other);
    // note: may want to have the history of the rolled dices (when there are
    // multiple dices)
    int roll() const;

    Dice operator=(const Dice &other);

    /* accessors **************************************************************/
    int getFaces() const { return faces; }
    void setFaces(int newfaces) { faces = newfaces; }
    int getDiceNumber() const { return diceNumber; }
    void setDiceNumber(int newDiceNumber) { diceNumber = newDiceNumber; }

  private:
    int faces;
    int diceNumber;
};

#endif // DICE_H

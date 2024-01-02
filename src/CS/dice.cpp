#include "dice.h"
#include <QRandomGenerator>

/******************************************************************************/
/*                                constructors                                */
/******************************************************************************/

Dice::Dice(int _faces, int _diceNumber):
    SERIALIZER(faces, diceNumber),
    faces(_faces),
    diceNumber(_diceNumber)
{}

Dice::Dice(const Dice &other) : Dice(other.faces, other.diceNumber) {}

/******************************************************************************/
/*                                 functions                                  */
/******************************************************************************/

int Dice::roll() const {
    int result = 0;

    for (int i = 0; i < diceNumber; ++i) {
        result += QRandomGenerator::global()->bounded(faces) + 1;
    }
    return result;
}

Dice Dice::operator=(const Dice &other) {
    faces = other.faces;
    diceNumber = other.diceNumber;
    return *this;
}

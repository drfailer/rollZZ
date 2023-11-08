#include "dice.h"
#include <QRandomGenerator>

Dice::Dice(int faces, int number):
    faces(faces),
    diceNumber(number)
{

}

Dice::Dice(const Dice &other):
    faces(other.faces),
    diceNumber(other.diceNumber)
{
}

int Dice::roll() const
{
    int result = 0;

    for (int i = 0; i < diceNumber; ++i) {
        result += QRandomGenerator::global()->bounded(faces) + 1;
    }
    return result;
}

Dice Dice::operator=(const Dice &other)
{
    faces = other.faces;
    diceNumber = other.diceNumber;
    return *this;
}

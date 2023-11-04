#include "dice.h"
#include <QRandomGenerator>

Dice::Dice(int faces, int number):
    faces(faces),
    diceNumber(number)
{

}

int Dice::roll() const
{
    int result = 0;

    for (int i = 0; i < diceNumber; ++i) {
        result += QRandomGenerator::global()->bounded(faces);
    }
    return result;
}

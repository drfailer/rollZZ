#ifndef DICE_H
#define DICE_H

// TODO: move this class elsewhere
class Dice
{
public:
    Dice(int faces, int number);
    // note: may want to have the history of the rolled dices (when there are multiple dices)
    int roll() const;

private:
    int faces;
    int diceNumber;
};

#endif // DICE_H

#ifndef DICE_H
#define DICE_H

// TODO: move this class elsewhere
class Dice
{
public:
    Dice(int faces = 20, int number = 1);
    Dice(const Dice& other);
    // note: may want to have the history of the rolled dices (when there are multiple dices)
    int roll() const;

    Dice operator=(const Dice& other);

private:
    int faces;
    int diceNumber;
};

#endif // DICE_H

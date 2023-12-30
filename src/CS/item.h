#ifndef CS_ITEM_H
#define CS_ITEM_H

#include <QString>

// TODO: move this class elsewhere
namespace CS {

class Item
{
public:
    Item(QString name = "", QString description = "", int quantity = 0, int weight = 0);

    /* accessors ***************************************************************/
    QString getName() const { return name; }
    void setName(const QString &newName) { name = newName; }
    QString getDescription() const { return description; }
    void setDescription(const QString &newDescription) { description = newDescription; }
    int getQuantity() const { return quantity; }
    void setQuantity(int newQuantity) { quantity = newQuantity; }
    int getWeight() const { return weight; }
    void setWeight(int newWeight) { weight = newWeight; }

private:
    QString name;
    QString description;
    int quantity;
    int weight;
};

} // namespace CS

#endif // ITEM_H

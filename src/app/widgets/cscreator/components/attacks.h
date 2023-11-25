#ifndef ATTACKS_H
#define ATTACKS_H

#include "component.h"

namespace CSCreator {

class AttacksPopup;

class Attacks : public Component
{
    Q_OBJECT
public:
    Attacks(const QString name = "name", int maxItems = 3, QWidget *parent = nullptr);
    void settingsPopup() override;

private:
    QString name;
    int maxItems;
    QLabel nameLabel;
    QLabel maxItemsLabel;

    AttacksPopup *attacksPopup = nullptr;
};

} // end namespace CSCreator

#endif // ATTACKS_H

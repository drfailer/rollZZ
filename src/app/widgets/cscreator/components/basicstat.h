#ifndef BASICSTAT_H
#define BASICSTAT_H

#include "component.h"

#include <QLabel>
#include <QWidget>
#include <QString>
#include <dice.h>

namespace CSCreator {

class BasicStatPopup;

class BasicStat : public Component
{
    Q_OBJECT
public:
    BasicStat(int valueMax, Dice dice, const QString& name, const QString& title, QWidget *parent = nullptr);
    BasicStat(int valueMax, Dice dice, const QString& name, QWidget *parent = nullptr);
    virtual void settingsPopup();
    virtual ~BasicStat() {}
    QString getName() const { return nameLabel.text(); }

private:
    BasicStatPopup *basicStatPopup = nullptr;

protected:
    QLabel valueMaxLabel;
    QLabel diceLabel;
    QLabel nameLabel;
    QString name;
    int valueMax;
    Dice dice; // NOTE: it would be better to find an alternative to this

    void updateLabels();
};

} // end namespace CSCreator

#endif // BASICSTAT_H

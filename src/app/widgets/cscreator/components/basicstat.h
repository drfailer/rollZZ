#ifndef CSCREATOR_BASICSTAT_H
#define CSCREATOR_BASICSTAT_H

#include "CS/basicstat.h"
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
    BasicStat(CS::BasicStat *basicStat, int valueMax, Dice dice, const QString& name, const QString& title, QWidget *parent = nullptr);
    BasicStat(CS::BasicStat *basicStat, int valueMax, Dice dice, const QString& name, QWidget *parent = nullptr);
    virtual void settingsPopup();
    virtual ~BasicStat() {}
    QString getName() const { return nameLabel.text(); }

private:
    BasicStatPopup *basicStatPopup = nullptr;

protected:
    QLabel valueMaxLabel;
    QLabel diceLabel;
    QLabel nameLabel;

    CS::BasicStat *basicStat = nullptr;

    virtual void update(int valueMax, Dice dice, const QString& name);
};

} // end namespace CSCreator

#endif // BASICSTAT_H

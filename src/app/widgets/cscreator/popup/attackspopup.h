#ifndef ATTACKSPOPUP_H
#define ATTACKSPOPUP_H

#include "cscreatorpopup.h"

#include <QComboBox>
#include <QLineEdit>
#include <QSpinBox>

namespace CSCreator {

class AttacksPopup : public CSCreatorPopup
{
    Q_OBJECT
public:
    AttacksPopup(const QString name = "name", int maxItems = 3);
    QString getName() const { return nameEdit.text(); }
    int getMaxItems() const { return maxItemsEdit.value(); }

private:
    QLineEdit nameEdit;
    QSpinBox maxItemsEdit;
    // QComboBox dataBaseEdit;
};

} // end namespace CScreator

#endif // ATTACKSPOPUP_H

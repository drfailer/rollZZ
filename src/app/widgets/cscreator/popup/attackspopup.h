#ifndef CSEDITOR_ATTACKSPOPUP_H
#define CSEDITOR_ATTACKSPOPUP_H

#include "tools/popup.h"

#include <QComboBox>
#include <QLineEdit>
#include <QSpinBox>

namespace CSCreator {

class AttacksPopup : public Tools::Popup {
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

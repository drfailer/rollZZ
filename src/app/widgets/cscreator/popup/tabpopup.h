#ifndef CSEDITOR_TABPOPUP_H
#define CSEDITOR_TABPOPUP_H

#include "tools/popup.h"
#include <QLineEdit>
#include <QWidget>

namespace CSCreator {

class TabPopup : public Popup
{
    Q_OBJECT
public:
    TabPopup(const QString& name, const QString& defaultText);
    TabPopup(const QString& name);
    QString getName() const { return nameEdit.text(); }

private:
    QLineEdit nameEdit;
};

} // end namespace CSCreator

#endif // TABPOPUP_H

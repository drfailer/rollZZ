#ifndef CSEDITOR_TABPOPUP_H
#define CSEDITOR_TABPOPUP_H

#include "cscreatorpopup.h"
#include <QLineEdit>
#include <QWidget>

namespace CSCreator {

class TabPopup : public CSCreatorPopup
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

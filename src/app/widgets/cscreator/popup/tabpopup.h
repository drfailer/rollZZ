#ifndef TABPOPUP_H
#define TABPOPUP_H

#include "cscreatorpopup.h"
#include <QLineEdit>
#include <QWidget>

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

#endif // TABPOPUP_H

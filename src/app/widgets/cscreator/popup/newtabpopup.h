#ifndef NEWTABPOPUP_H
#define NEWTABPOPUP_H

#include "cscreatorpopup.h"
#include <QLineEdit>
#include <QWidget>

class NewTabPopup : public CSCreatorPopup
{
    Q_OBJECT
public:
    NewTabPopup();
    QString getName() const { return nameEdit.text(); }

private:
    QLineEdit nameEdit;
};

#endif // NEWTABPOPUP_H

#ifndef CATEGORYCREATIONPOPUP_H
#define CATEGORYCREATIONPOPUP_H

#include "cscreatorpopup.h"

#include <QLineEdit>

class CategoryCreationPopup : public CSCreatorPopup
{
    Q_OBJECT
public:
    CategoryCreationPopup();
    QString getName() const { return nameEdit.text(); }

private:
    QLineEdit nameEdit;
};

#endif // CATEGORYCREATIONPOPUP_H

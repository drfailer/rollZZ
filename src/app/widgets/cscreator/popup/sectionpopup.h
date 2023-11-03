#ifndef SECTIONPOPUP_H
#define SECTIONPOPUP_H

#include "cscreatorpopup.h"

#include <QLineEdit>

class SectionPopup : public CSCreatorPopup
{
    Q_OBJECT
public:
    SectionPopup();
    QString getName() const { return nameEdit.text(); }

private:
    QLineEdit nameEdit;
};

#endif // SECTIONPOPUP_H

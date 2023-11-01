#ifndef DESCRIPTORCREATIONPOPUP_H
#define DESCRIPTORCREATIONPOPUP_H

#include "cscreatorpopup.h"

#include <QLineEdit>

class DescriptorCreationPopup : public CSCreatorPopup
{
    Q_OBJECT
public:
    DescriptorCreationPopup();
    QString getName() const { return nameEdit.text(); }

private:
    QLineEdit nameEdit;
};

#endif // DESCRIPTORCREATIONPOPUP_H

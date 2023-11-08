#ifndef DESCRIPTORPOPUP_H
#define DESCRIPTORPOPUP_H

#include "cscreatorpopup.h"

#include <QLineEdit>

namespace CSCreator {

class DescriptorPopup : public CSCreatorPopup
{
    Q_OBJECT
public:
    DescriptorPopup();
    QString getName() const { return nameEdit.text(); }

private:
    QLineEdit nameEdit;
};

} // end namespace CSCreator

#endif // DESCRIPTORPOPUP_H

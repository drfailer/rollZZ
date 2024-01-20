#ifndef CSEDITOR_DESCRIPTORPOPUP_H
#define CSEDITOR_DESCRIPTORPOPUP_H

#include "tools/popup.h"
#include "CS/descriptor.h"

#include <QLineEdit>
#include <QComboBox>

namespace CSCreator {

class DescriptorPopup : public Popup
{
    Q_OBJECT
public:
    DescriptorPopup(const QString& name = "name", CS::DescriptorTypes type = CS::LONG);
    QString getName() const { return nameEdit.text(); }
    CS::DescriptorTypes getType() const {
        return (CS::DescriptorTypes) typeEdit.currentIndex();
    }

private:
    QLineEdit nameEdit;
    QComboBox typeEdit;
};

} // end namespace CSCreator

#endif // DESCRIPTORPOPUP_H

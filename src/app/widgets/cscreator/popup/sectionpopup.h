#ifndef CSEDITOR_SECTIONPOPUP_H
#define CSEDITOR_SECTIONPOPUP_H

#include "tools/popup.h"

#include <QLineEdit>

namespace CSCreator {

class SectionPopup : public Tools::Popup {
    Q_OBJECT
public:
    SectionPopup();
    SectionPopup(const QString& defaultValue);
    QString getName() const { return nameEdit.text(); }

private:
    QLineEdit nameEdit;
};

} // end namespace CSCrator

#endif // SECTIONPOPUP_H

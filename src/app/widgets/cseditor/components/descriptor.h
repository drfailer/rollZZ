#ifndef CSEDITOR_DESCRIPTOR_H
#define CSEDITOR_DESCRIPTOR_H

#include "component.h"
#include "CS/descriptor.h"
#include <QTextEdit>

namespace CSEditor {

class Descriptor : public Component
{
    Q_OBJECT
public:
    Descriptor(CS::Descriptor *descriptor, QWidget* parent = nullptr);

private:
    CS::Descriptor *descriptor = nullptr;
};

} // end namespace CSEditor

#endif // DESCRIPTOR_H

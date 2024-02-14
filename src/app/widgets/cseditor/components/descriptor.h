#ifndef CSEDITOR_DESCRIPTOR_H
#define CSEDITOR_DESCRIPTOR_H

#include "tools/component.h"
#include "CS/descriptor.h"

namespace CSEditor {

class Descriptor : public Tools::Component
{
    Q_OBJECT
public:
    Descriptor(CS::Descriptor *descriptor, QWidget* parent = nullptr);

private:
    CS::Descriptor *descriptor = nullptr;
};

} // end namespace CSEditor

#endif // DESCRIPTOR_H

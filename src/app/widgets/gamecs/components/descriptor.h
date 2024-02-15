#ifndef GAMECS_DESCRIPTOR_H
#define GAMECS_DESCRIPTOR_H

#include "tools/component.h"
#include "CS/descriptor.h"

namespace GameCS {

class Descriptor : public Tools::Component
{
    Q_OBJECT
public:
    Descriptor(CS::Descriptor *descriptor, QWidget* parent = nullptr);

private:
    CS::Descriptor *descriptor = nullptr;
};

} // end namespace GameCS

#endif // DESCRIPTOR_H

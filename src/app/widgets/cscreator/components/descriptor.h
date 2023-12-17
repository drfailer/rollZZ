#ifndef CSCREATOR_DESCRIPTOR_H
#define CSCREATOR_DESCRIPTOR_H

#include "component.h"
#include "CS/descriptor.h"

namespace CSCreator {

class DescriptorPopup;

class Descriptor : public Component
{
    Q_OBJECT
public:
    Descriptor(CS::Descriptor *descriptor, const QString& name = "name", QWidget* parent = nullptr);
    void settingsPopup() override;

private:
    QLabel nameLabel;

    DescriptorPopup *descriptorPopup = nullptr;
    CS::Descriptor *descriptor = nullptr;

    void update(const QString& name);
};

} // end namespace CSCreator

#endif // DESCRIPTOR_H

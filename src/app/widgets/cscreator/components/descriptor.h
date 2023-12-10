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
    QString name;

    DescriptorPopup *descriptorPopup = nullptr;
    CS::Descriptor *descriptor = nullptr;
};

} // end namespace CSCreator

#endif // DESCRIPTOR_H

#ifndef DESCRIPTOR_H
#define DESCRIPTOR_H

#include "component.h"

namespace CSCreator {

class DescriptorPopup;

class Descriptor : public Component
{
    Q_OBJECT
public:
    Descriptor(const QString& name, QWidget* parent);
    Descriptor();
    void settingsPopup();

private:
    QLabel nameLabel;
    QString name;

    DescriptorPopup *descriptorPopup = nullptr;
};

} // end namespace CSCreator

#endif // DESCRIPTOR_H

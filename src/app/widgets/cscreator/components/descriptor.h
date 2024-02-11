#ifndef CSCREATOR_DESCRIPTOR_H
#define CSCREATOR_DESCRIPTOR_H

#include "CS/descriptor.h"
#include "component.h"

namespace CSCreator {

class DescriptorPopup;

class Descriptor : public Component {
    Q_OBJECT
  public:
    Descriptor(CS::Descriptor *descriptor, QWidget *parent = nullptr);
    void settingsPopup() override;

  private:
    QLabel nameLabel;
    QLabel typeLabel;

    DescriptorPopup *descriptorPopup = nullptr;
    CS::Descriptor *descriptor = nullptr;

    void update(const QString &name, CS::DescriptorTypes type);
    QString typeToString(CS::DescriptorTypes type) const;
};

} // end namespace CSCreator

#endif // DESCRIPTOR_H

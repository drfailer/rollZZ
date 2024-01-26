#ifndef CSEDITOR_SECTION_H
#define CSEDITOR_SECTION_H

#include "cseditor/components/component.h"
#include "CS/section.h"

#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QFrame>

namespace CSEditor {

class Section;
class BasicStat;
class BonusStat;
class ListStat;
class Descriptor;
class Equipment;
class Attacks;

class Section : public Component
{
    Q_OBJECT
public:
    explicit Section(CS::Section* section, QWidget *parent = nullptr);
    ~Section();

private:
    CS::Section *section;
};

} // end namespace CSCrator

#endif // CSEDITORSECTION_H

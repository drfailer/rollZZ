#ifndef GAMECS_SECTION_H
#define GAMECS_SECTION_H

#include "CS/section.h"
#include "tools/component.h"

#include <QComboBox>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

namespace GameCS {

class Section;
class BasicStat;
class BonusStat;
class ListStat;
class Descriptor;
class Equipment;
class Attacks;

class Section : public Tools::Component {
    Q_OBJECT
  public:
    Section(CS::Section *section, QWidget *parent = nullptr);
    ~Section();

  signals:
    void rolled(QString message);

  private:
    CS::Section *section;
};

} // namespace GameCS

#endif // CSEDITORSECTION_H

#ifndef CSEDITOR_SKILL_HPP
#define CSEDITOR_SKILL_HPP

#include <QWidget>
#include <QBoxLayout>
#include <qspinbox.h>
#include "CS/caracteristic.h"

namespace CSEditor {

class Caracteristic : public QWidget {
    Q_OBJECT
  public:
    Caracteristic(CS::Caracteristic* caracteristic, QWidget* parent = nullptr);
    ~Caracteristic() = default;

  private:
    CS::Caracteristic* caracteristic;
    QHBoxLayout layout;
    QSpinBox bonusEdit;
};

} // end namespace CSEditor

#endif

#ifndef GAMECS_SKILL_HPP
#define GAMECS_SKILL_HPP

#include "CS/caracteristic.h"
#include <QBoxLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QWidget>

namespace GameCS {

class Caracteristic : public QWidget {
    Q_OBJECT
  public:
    Caracteristic(CS::Caracteristic *caracteristic, QWidget *parent = nullptr);
    ~Caracteristic() = default;

  signals:
    void rolled(QString message);

  private:
    CS::Caracteristic *caracteristic;
    QHBoxLayout layout;
    QPushButton rollBtn;
};

} // end namespace GameCS

#endif

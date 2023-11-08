#ifndef BASICSTAT_H
#define BASICSTAT_H

#include <QLabel>
#include <QWidget>

namespace CSCreator {

class BasicStat : public QWidget
{
    Q_OBJECT
public:
    explicit BasicStat(QWidget *parent = nullptr);

private:
    QLabel name;
};

} // end namespace CSCreator

#endif // BASICSTAT_H

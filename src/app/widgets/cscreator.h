#ifndef CSCREATOR_H
#define CSCREATOR_H

#include <QPushButton>
#include <QWidget>
#include <QGridLayout>

class CSCreator : public QWidget
{
    Q_OBJECT
public:
    explicit CSCreator(QWidget *parent = nullptr);
    ~CSCreator();

    void config(QPushButton *newStat, QGridLayout *statList);

private:
    QPushButton *newStat;
    QGridLayout *statList;
    int index = 0;
};

#endif // CSCREATOR_H

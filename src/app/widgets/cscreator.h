#ifndef CSCREATOR_H
#define CSCREATOR_H

#include "statcreationpopup.h"

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

private slots:
    void addStatPopup();
    void addStat();

private:
    QPushButton *newStat;
    QGridLayout *statList;
    StatCreationPopup *statCreationPopup;
    int index = 0;
};

#endif // CSCREATOR_H

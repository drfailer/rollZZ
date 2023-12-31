#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include "widgets/cscreator/cscreator.h"
#include "widgets/gamelist.h"
#include "widgets/map/mapwidget.h"
#include "mainwindowui.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void goToPage(QWidget *w);

private:
    Ui::MainWindow *ui;
    GameList *gameList;
    CSCreator::CSCreator *csCreator;
    MapWidget* mapWidget;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "cs.h"
#include "widgets/gamelist.h"
#include "cseditor/cseditor.h"
#include "cscreator/cscreator.h"

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
    CSCreator::CSCreator *csCreator = nullptr;
    CSEditor::CSEditor *csEditor = nullptr;
    CS::CS CSTree;
};
#endif // MAINWINDOW_H

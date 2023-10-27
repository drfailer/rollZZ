#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QMenuBar>
#include <QLayout>

class MainMenu: public QWidget
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();
    void update();

private:
    QWidget *parent;
    // QMenuBar sideMenu;
    // QMenuBar topMenu;
    // QVBoxLayout menuLayout;
};

#endif // MAINMENU_H

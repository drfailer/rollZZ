#include "mainmenu.h"
#include <iostream>

MainMenu::MainMenu(QWidget *parent):
    QWidget(parent),
    parent(parent)
{
    /* building the menus */

    // top
    // sideMenu.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    // topMenu.setObjectName("topMenu");
    // topMenu.setFixedSize(2000, 50);
    // topMenu.setStyleSheet("color: white; background-color: blue; font-size: 20;");
    // topMenu.addMenu("&testtop");

    // side
    // topMenu.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    // topMenu.setObjectName("sideMenu");
    // topMenu.setFixedSize(50, 200);
    // sideMenu.setStyleSheet("color: white; background-color: yellow; font-size: 20;");
    // sideMenu.addMenu("&testside");

    // menuLayout.addStretch();
    // menuLayout.setContentsMargins(0, 0, 0, 0);
    // menuLayout.addWidget(&topMenu);
    // menuLayout.addWidget(&sideMenu);
}

MainMenu::~MainMenu()
{
}

void MainMenu::update()
{
}

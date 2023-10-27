#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLayout>
#include <iostream>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mainMenu(MainMenu(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    mainMenu.update();
}


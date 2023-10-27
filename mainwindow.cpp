#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLayout>
#include <iostream>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // ui contient les items créés dans le designer
    // le setup permet de parser et récupérer les élément du fichier .ui (généré avec le designer)
    ui->setupUi(this);

    // accès au body label
    ui->bodyLabel->setText("rollZZ");

    // on utilise des connects pour exécuter une fonction lorsque le bouton est préssé
    connect(ui->mainIconButton, &QPushButton::clicked, this, [&](){ std::cout << "rollZZ" << std::endl; ui->bodyLabel->setText("rollZZ"); });
    connect(ui->createGameButton, &QPushButton::clicked, this, [&](){ std::cout << "create game" << std::endl; ui->bodyLabel->setText("create game"); });
    connect(ui->joinGameButton, &QPushButton::clicked, this, [&](){ std::cout << "join game" << std::endl; ui->bodyLabel->setText("join game"); });
    connect(ui->characterSheetButton, &QPushButton::clicked, this, [&](){ std::cout << "charater sheet" << std::endl; ui->bodyLabel->setText("charater sheet"); });
    connect(ui->settingsButton, &QPushButton::clicked, this, [&](){ std::cout << "settings" << std::endl; ui->bodyLabel->setText("settings"); });

    // TODO: répartir les éléments de l'ui dans des classes pour simplifier la gestion
    // NOTE: à terme, on ne changera que ce qu'il y a dansle body (les menus pas besoins d'y toucher)
    // TODO (UI): remplacer le texte des boutons par une icone
}

MainWindow::~MainWindow()
{
    delete ui;
}

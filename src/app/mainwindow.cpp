#include "mainwindow.h"
#include "../../ressources/ui_mainwindow.h"
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

    // on utilise des connects pour exécuter une fonction lorsque le bouton est préssé
    connect(ui->mainIconButton, &QPushButton::clicked, this, [&]() { goTo(ui->mainPage); });
    connect(ui->createGameButton, &QPushButton::clicked, this, [&]() { goTo(ui->createGamePage); });
    connect(ui->joinGameButton, &QPushButton::clicked, this, [&]() { goTo(ui->joinGamePage); });
    connect(ui->characterSheetButton, &QPushButton::clicked, this, [&]() { goTo(ui->charactersSheetsPage); });
    connect(ui->settingsButton, &QPushButton::clicked, this, [&]() { goTo(ui->settingsPage); });

    // TODO: répartir les éléments de l'ui dans des classes pour simplifier la gestion
    // NOTE: à terme, on ne changera que ce qu'il y a dansle body (les menus pas besoins d'y toucher)
    // TODO (UI): remplacer le texte des boutons par une icone
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goTo(QWidget* w)
{
    ui->pages->setCurrentIndex(ui->pages->indexOf(w));
}

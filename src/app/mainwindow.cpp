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

    // we start on the main page
    goToPage(ui->mainPage);

    // on utilise des connects pour exécuter une fonction lorsque le bouton est préssé
    connect(ui->mainIconButton, &QPushButton::clicked, this, [&]() { goToPage(ui->mainPage); });
    connect(ui->createGameButton, &QPushButton::clicked, this, [&]() { goToPage(ui->createGamePage); });
    connect(ui->joinGameButton, &QPushButton::clicked, this, [&]() { goToPage(ui->joinGamePage); });
    connect(ui->characterSheetButton, &QPushButton::clicked, this, [&]() { goToPage(ui->charactersSheetsPage); });
    connect(ui->settingsButton, &QPushButton::clicked, this, [&]() { goToPage(ui->settingsPage); });

    int index=0;
    connect(ui->createCS, &QPushButton::clicked,this,[&](){goToPage(ui->characterSheetCreator);});
    connect(ui->addNewStat, &QPushButton::clicked,this,[&](){ui->CSLayout->addWidget(new QPushButton("Button Text"), index/3, index%3); index++;});

    // TODO: répartir les éléments de l'ui dans des classes pour simplifier la gestion
    // NOTE: à terme, on ne changera que ce qu'il y a dansle body (les menus pas besoins d'y toucher)
    // TODO (UI): remplacer le texte des boutons par une icone

    // create pages elements

    // NOTE: à voir si on fait un max de chose avec le designer (et donc on aura
    // plein de petits éléments comme ça) ou si on crée les pages à la main.
    gameList = new GameList({ "Meilleur MJ", "MJ bauf mais ça passe encore"}, ui->gamesList);
    // gameList = new GameList({}, ui->gamesList);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goToPage(QWidget *w)
{
    ui->pages->setCurrentIndex(ui->pages->indexOf(w));
}

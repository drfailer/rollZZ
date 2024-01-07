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

    /***************************************************************************/
    /* Top level pages                                                         */
    /***************************************************************************/

    // we start on the main page
    goToPage(ui->mainPage);

    // on utilise des connects pour exécuter une fonction lorsque le bouton est préssé
    connect(ui->mainIconButton, &QPushButton::clicked, this, [&]() { goToPage(ui->mainPage); });
    connect(ui->createGameButton, &QPushButton::clicked, this, [&]() { goToPage(ui->createGamePage); });
    connect(ui->joinGameButton, &QPushButton::clicked, this, [&]() { goToPage(ui->joinGamePage); });
    connect(ui->characterSheetButton, &QPushButton::clicked, this, [&]() { goToPage(ui->CSPage); });
    connect(ui->settingsButton, &QPushButton::clicked, this, [&]() { goToPage(ui->settingsPage); });

    /***************************************************************************/
    /* Games acces page                                                        */
    /***************************************************************************/

    // TODO: use the games of a real player (needs player class)
    gameList = new GameList({ new map::Game("Meilleur MJ"), new map::Game("MJ bauf mais ça passe encore")},ui->gamesList);
    connect(gameList,&GameList::setGame,this,[&](map::Game* gameToLaunch){mapWidget = new MapWidget(ui->playerBoardPage,gameToLaunch->getMap()); goToPage(ui->playerBoardPage);});

    /***************************************************************************/
    /* Character sheets creation                                               */
    /***************************************************************************/

    CSCreator::CSCreatorConfig csCreatorConfig = {
        .contentWgt = ui->CSCreatorContent,
        .newTabBtn = ui->CSCreatornewTabBtn,
        .saveBtn = ui->CSCreatorSaveBtn,
        .importBtn = ui->CSCreatorImportBtn,
    };
    csCreator = new CSCreator::CSCreator(csCreatorConfig, ui->CSCreator);
    connect(ui->createTemplate, &QPushButton::clicked, this, [&](){ ui->CSPages->setCurrentIndex(ui->CSPages->indexOf(ui->CSCreator)); });
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gameList;
    delete csCreator;
    delete mapWidget;
}

void MainWindow::goToPage(QWidget *w)
{
    ui->pages->setCurrentIndex(ui->pages->indexOf(w));
}

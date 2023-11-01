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

    // TODO: use the games of a real player (needs palyer class)
    gameList = new GameList({ "Meilleur MJ", "MJ bauf mais ça passe encore"}, ui->gamesList);
    // gameList = new GameList({}, ui->gamesList);

    /***************************************************************************/
    /* Character sheets creation                                               */
    /***************************************************************************/

    CSCreatorConfig csCreatorConfig = {
        .addCategoryBtn = ui->addCategoryBtn,
        .addDescritorBtn = ui->addDescriptorBtn,
        .addStatBtn = ui->addStatBtn,
        .addEquipmentBtn = ui->addEquipmentBtn,
        .addMoneyBtn = ui->addMoneyBtn,
        .sheetContent = ui->CSContent
    };
    csCreator = new CSCreator(csCreatorConfig, ui->CSCreator);
    connect(ui->createTemplate, &QPushButton::clicked, this, [&](){ ui->CSPages->setCurrentIndex(ui->CSPages->indexOf(ui->CSCreator)); });
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gameList;
    delete csCreator;
}

void MainWindow::goToPage(QWidget *w)
{
    ui->pages->setCurrentIndex(ui->pages->indexOf(w));
}

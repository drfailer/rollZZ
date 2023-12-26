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
    connect(ui->characterSheetButton, &QPushButton::clicked, this, [&]() {
        ui->CSPages->setCurrentIndex(0);
        goToPage(ui->CSPage);
    });
    connect(ui->settingsButton, &QPushButton::clicked, this, [&]() { goToPage(ui->settingsPage); });

    /***************************************************************************/
    /* Games acces page                                                        */
    /***************************************************************************/

    // TODO: use the games of a real player (needs palyer class)
    gameList = new GameList({ "Meilleur MJ", "MJ bauf mais ça passe encore"}, ui->gamesList);
    // gameList = new GameList({}, ui->gamesList);

    // TODO: create a class for this v

    /***************************************************************************/
    /* Character sheets creation                                               */
    /***************************************************************************/

    CSCreator::CSCreatorConfig csCreatorConfig = {
        .contentWgt = ui->CSCreatorContent,
        .newTabBtn = ui->CSCreatornewTabBtn,
        .saveBtn = ui->CSCreatorSaveBtn,
        .importBtn = ui->CSCreatorImportBtn,
    };
    csCreator = new CSCreator::CSCreator(csCreatorConfig, &CSTree, ui->CSCreator);
    connect(ui->createTemplate, &QPushButton::clicked, this, [&](){ ui->CSPages->setCurrentIndex(ui->CSPages->indexOf(ui->CSCreator)); });

    /***************************************************************************/
    /* Character sheets edition                                                */
    /***************************************************************************/
    // WARN: the CSTree should be different here, but for now we keep it like
    // this for the test

    // this is for testing the display of the cseditor:
    QHBoxLayout* CSListLyt = new QHBoxLayout();
    QPushButton* testCSBtn = new QPushButton();
    ui->CSList->setLayout(CSListLyt);
    CSListLyt->addWidget(testCSBtn);
    connect(testCSBtn, &QPushButton::clicked, this, [&](){
                if (csEditor != nullptr) {
                    delete csEditor;
                    csEditor = nullptr;
                }
                CSEditor::CSEditorConfig csEditorConfig = {
                    .contentWgt = ui->CSEditorContent,
                    .saveBtn = ui->CSEditorSaveBtn,
                    .importBtn = ui->CSEditorImportBtn,
                };
                csEditor = new CSEditor::CSEditor(csEditorConfig, &CSTree, ui->CSEditor);
                ui->CSPages->setCurrentIndex(ui->CSPages->indexOf(ui->CSEditor));
            });
}

MainWindow::~MainWindow()
{
    delete gameList;
    delete csCreator;
}

void MainWindow::goToPage(QWidget *w)
{
    ui->pages->setCurrentIndex(ui->pages->indexOf(w));
}

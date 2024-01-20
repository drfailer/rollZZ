#include "mainwindow.h"
#include "../../ressources/ui_mainwindow.h"
#include <QLayout>
#include <QDir>
#include <iostream>
#include "config.h"
#include <QPushButton>

/******************************************************************************/
/*                          constructor & destructor                          */
/******************************************************************************/

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // ui contient les items créés dans le designer
    // le setup permet de parser et récupérer les élément du fichier .ui (généré avec le designer)
    ui->setupUi(this);

    initMenu();
    initGames();
    initCSCreator();
    initCSEditor();
}

MainWindow::~MainWindow() {
    delete gameList;
    delete csCreator;
    delete csEditor;
}

/******************************************************************************/
/*                                 init Menu                                  */
/******************************************************************************/

void MainWindow::initMenu() {
    // we start on the main page
    goToPage(ui->mainPage);

    // on utilise des connects pour exécuter une fonction lorsque le bouton est préssé
    connect(ui->mainIconButton, &QPushButton::clicked, this,
            [&]() { goToPage(ui->mainPage); });
    connect(ui->createGameButton, &QPushButton::clicked, this,
            [&]() { goToPage(ui->createGamePage); });
    connect(ui->joinGameButton, &QPushButton::clicked, this,
            [&]() { goToPage(ui->joinGamePage); });
    connect(ui->characterSheetButton, &QPushButton::clicked, this, [&]() {
                ui->CSPages->setCurrentIndex(0);
                goToPage(ui->CSPage);
            });
    connect(ui->settingsButton, &QPushButton::clicked, this,
            [&]() { goToPage(ui->settingsPage); });
}

/******************************************************************************/
/*                                 init games                                 */
/******************************************************************************/

void MainWindow::initGames() {
    // TODO: use the games of a real player (needs palyer class)
    gameList = new GameList({ "Meilleur MJ", "MJ bauf mais ça passe encore"}, ui->gamesList);
    // gameList = new GameList({}, ui->gamesList);
}

/******************************************************************************/
/*                               init CSCreator                               */
/******************************************************************************/

void MainWindow::initCSCreator() {
    CSCreator::CSCreatorConfig csCreatorConfig = {
        .contentWgt = ui->CSCreatorContent,
        .newTabBtn = ui->CSCreatornewTabBtn,
        .saveBtn = ui->CSCreatorSaveBtn,
        .importBtn = ui->CSCreatorImportBtn,
    };
    csCreator = new CSCreator::CSCreator(csCreatorConfig, &CSTree, ui->CSCreator);
    connect(ui->createTemplate, &QPushButton::clicked, this, [&](){
                ui->CSPages->setCurrentIndex(ui->CSPages->indexOf(ui->CSCreator));
            });
}

/******************************************************************************/
/*                               init CSEditor                                */
/******************************************************************************/

void MainWindow::initCSEditor() {
    // WARN: the CSTree should be different here, but for now we keep it like
    // this for the test

    // TODO: move this in a method

    // this should be done in another class (CharactersManager) and it should
    // handle the character creation

    QHBoxLayout* CSListLyt = new QHBoxLayout();
    QDir csDirectory(CS_DIRECTORY);
    QStringList csFiles = csDirectory.entryList(QStringList(), QDir::Files);
    CSEditor::CSEditorConfig csEditorConfig = {
        .contentWgt = ui->CSEditorContent,
        .saveBtn = ui->CSEditorSaveBtn,
        .importBtn = ui->CSEditorImportBtn,
    };

    CSListLyt->setAlignment(Qt::AlignTop);
    ui->CSList->setLayout(CSListLyt);

    connect(ui->createCS, &QPushButton::clicked, this, [&]() {
            // TODO: popup to create a cs (generate file name)
            });

    for (const QString& csFile : csFiles) {
        // TODO: get the character name
        QPushButton* testCSBtn = new QPushButton(csFile, this);
        CSListLyt->addWidget(testCSBtn);
        connect(testCSBtn, &QPushButton::clicked, this, [&, csFile, csEditorConfig](){
                // NOTE: we can optimize here by saving the name of the current
                // character and not reloading the same file.
                if (csEditor != nullptr) {
                    delete csEditor;
                    csEditor = nullptr;
                }
                CSTree.load(CS_DIRECTORY + csFile);
                csEditor = new CSEditor::CSEditor(csEditorConfig, &CSTree, ui->CSEditor);
                ui->CSPages->setCurrentIndex(ui->CSPages->indexOf(ui->CSEditor));
            });
    }
}

/******************************************************************************/
/*                              helper functions                              */
/******************************************************************************/

void MainWindow::goToPage(QWidget *w) {
    ui->pages->setCurrentIndex(ui->pages->indexOf(w));

}

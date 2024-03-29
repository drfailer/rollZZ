#include "mainwindow.h"
#include "../../ressources/ui_mainwindow.h"
#include <QLayout>
#include <QDir>
#include <iostream>
#include "config.h"
#include "popup/createcharacterpopup.h"
#include "tools/popup.h"
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
    // TODO: use the games of a real player (needs player class)
    gameList = new GameList({ new Game("Meilleur MJ"), new Game("MJ bauf mais ça passe encore")},ui->gamesList);
    connect(gameList,&GameList::setGame,this,[&](Game* gameToLaunch){mapWidget = new MapWidget(ui->playerBoardPage,gameToLaunch->getDefaultMap()); goToPage(ui->playerBoardPage);});
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
    QVBoxLayout* CSListLyt = new QVBoxLayout();
    QDir csDirectory(CS_DIRECTORY);
    QStringList csFiles = csDirectory.entryList(QStringList(), QDir::Files);

    CSListLyt->setAlignment(Qt::AlignTop);
    ui->CSList->setLayout(CSListLyt);

    // connect newCS button
    connect(ui->createCS, &QPushButton::clicked, this, [&]() {
        if (createCharacterPopup == nullptr) {
            createCharacterPopup = new CreateCharacterPopup();
            createCharacterPopup->show();

            connect(createCharacterPopup, &Tools::Popup::confirm, this,
                [&](bool confirm) {
                    if (confirm) {
                        startCSEditor(
                                CS_DIRECTORY + createCharacterPopup->getName(),
                                createCharacterPopup->getTemplate()
                            );
                    }
                    delete createCharacterPopup;
                    createCharacterPopup = nullptr;
            });
        }
    });

    // create buttons for existing cs
    for (const QString& csFile : csFiles) {
        QPushButton* testCSBtn = new QPushButton(csFile, this);
        QString path = CS_DIRECTORY + csFile;

        CSListLyt->addWidget(testCSBtn);
        connect(testCSBtn, &QPushButton::clicked, this, [&, path](){
                startCSEditor(path);
            });
    }
}

/******************************************************************************/
/*                              helper functions                              */
/******************************************************************************/

void MainWindow::goToPage(QWidget *w) {
    ui->pages->setCurrentIndex(ui->pages->indexOf(w));
}

void MainWindow::startCSEditor(const QString& csFile, const QString& loadedFile) {
    CSEditor::CSEditorConfig csEditorConfig = {
        .contentWgt = ui->CSEditorContent,
        .saveBtn = ui->CSEditorSaveBtn,
        .importBtn = ui->CSEditorImportBtn,
        .csFile = csFile,
    };

    if (csEditor != nullptr) {
        if (csEditor->getCSFile() == csFile) {
            return; // we don't reload the same file
        }
        delete csEditor;
        csEditor = nullptr;
    }
    CSTree.load(loadedFile.isEmpty() ? csFile : loadedFile);
    csEditor = new CSEditor::CSEditor(csEditorConfig, &CSTree, ui->CSEditor);
    ui->CSPages->setCurrentIndex(ui->CSPages->indexOf(ui->CSEditor));
}


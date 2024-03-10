#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include "cs.h"
#include "widgets/gamelist.h"
#include "widgets/map/mapwidget.h"
#include <QMainWindow>
#include "cseditor/cseditor.h"
#include "cscreator/cscreator.h"
#include "User.h"
#include "gamepopup.h"
#include "joingamepopup.h"

class CreateCharacterPopup;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow {
    Q_OBJECT
  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  public slots:
    void goToPage(QWidget *w);
    void readyToLaunchGame(Game* g);

  private:
    Ui::MainWindow *ui;
    GameList *gameList;
    GamePopup* gamePopup;
    JoinGamePopup* joinGamePopup;
    MapWidget* mapWidget;
    CSCreator::CSCreator *csCreator = nullptr;
    CSEditor::CSEditor *csEditor = nullptr;
    CS::CS CSTree;
    QTimer* timer;
    User *user;

    /* popup ******************************************************************/
    CreateCharacterPopup *createCharacterPopup = nullptr;

    /* init functions *********************************************************/
    void initMenu();
    void initGames();
    void initCSCreator();
    void initCSEditor();

    /* helper functions *******************************************************/
    void startCSEditor(const QString& csFile, const QString& loadedFile = "");
};
#endif // MAINWINDOW_H

#ifndef GAMELIST_H
#define GAMELIST_H

#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>

class GameList : public QWidget
{
    Q_OBJECT
public:
    explicit GameList(const QList<QString>& games, QWidget *parent = nullptr);
    ~GameList();

private:
    // TODO: we use string for testing but this will be real games (or at least,
    // we will build a list of buttons with the player's games)
    QList<QString> games;
    QVBoxLayout layout;
};

#endif // GAMELIST_H

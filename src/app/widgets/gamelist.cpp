#include "gamelist.h"
#include "gamecs/gamecs.h"

#include <QPushButton>
#include <QDir>

GameList::GameList(const QList<QString>& games, QWidget *parent):
    QWidget(parent),
    games(games)
{
    setLayout(&layout);

    // adding the elements in the list of games
    if (games.empty()) {
        layout.addWidget(new QLabel("No game available"), Qt::AlignLeft|Qt::AlignTop);
    } else {
        // marche pas et je ne comprends pas pk
        layout.setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        for (const QString& elt : games) {
            QPushButton *btn = new QPushButton(elt);
            layout.addWidget(btn);
            connect(btn, &QPushButton::clicked, this, [&]() {
                    CSTree.load(QDir::homePath() + "/.local/share/rollZZ/cs/Talion");
                    gameCS = new GameCS::GameCS("file", &CSTree);
                    gameCS->show();
                });
        }
    }
}

GameList::~GameList()
{
}

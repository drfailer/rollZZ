#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  MainWindow   w;
  // on peut faire un steelsheet dans le code aussi :)
  w.setStyleSheet("QPushButton                { background-color: #282828; color: white; font-size: 18px; border: 0px; }"
                  "#QPushButton:hover         { background-color: #383838; }"
                  "#QPushButton:checked       { background-color: #303030; }"
                  "#QPushButton:checked:hover { background-color: #484848; }"
                  "#QLabel                    { color: #F2F2F2; }"
                  );
  w.show();
  return app.exec();
}

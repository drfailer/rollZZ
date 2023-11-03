#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QFile>
#include "./mongodb/mongodb.hpp"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  MainWindow   w;
  // on peut faire un steelsheet dans le code aussi :)
  // w.setStyleSheet("#QLabel                    { color: #F2F2F2; }");
  w.show();
  testt();
  return app.exec();
}

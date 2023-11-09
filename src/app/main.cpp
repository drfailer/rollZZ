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

  Dice d;
  MongoDB::init("rollZZ");
  //MongoDB::insertDocument(toDocument(d),"dice");
  //MongoDB::requestAll("dice");
  Dice d1 = toObject(MongoDB::requestOne("dice"));
  std::cout << "faces: " << d1.getFaces() << " & diceNumber:" << d1.getDiceNumber() << std::endl;
  return app.exec();
}

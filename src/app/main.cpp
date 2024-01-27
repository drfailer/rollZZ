#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QFile>
#include "init.h"

/* #define MAIN_TEST */

#ifndef MAIN_TEST
int main(int argc, char *argv[]) {
    init(); // we call the init function on start

    QApplication app(argc, argv);
    MainWindow   w;
    // on peut faire un steelsheet dans le code aussi :)
    // w.setStyleSheet("#QLabel                    { color: #F2F2F2; }");
    w.show();
    return app.exec();
}

#else
#include "component.h"
#include "part.h"

int main(int , char **) {
    CS::CS tree;

    tree.deserializeFile("test.txt");
    std::cout << tree.serialize() << std::endl;

    for (CS::Part * part : tree.getParts()) {
        std::cout << part->getName().toStdString() << std::endl;
        for (CS::Section *section : part->getSections()) {
            std::cout << "\t" << section->getTitle().toStdString() << std::endl;

            for (CS::Component *component : section->getComponents()) {
                std::cout << "\t\t" << component->getTitle().toStdString() << std::endl;
            }
        }
    }

    return 0;
}

#endif

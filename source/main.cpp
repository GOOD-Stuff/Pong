#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

/*
TODO:
Major:
 0 - All of it must be worked;
 1 - Add network class: responsible of set connection (UDP) and send position of
        second player and ball;
 2 - Add player class: responsible of move and interact player with ball;
 3 - Add drawer class: responsible of drawing players and ball;
 4 - Add interaction between ball and player;
 5 - Add control of player;
Minor:
 6 - Add some rule;
 7 - Add scoreboard;
 8 - Add setup of network connection;
*/

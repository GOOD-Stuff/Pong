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
 6 - Add game class: responsible of drawing game space;
Minor:
 7 - Add some rule;
 8 - Add scoreboard;
 9 - Add setup of network connection;
10 - Add setting class: responsible of drawing setting's menu and control logic;
*/

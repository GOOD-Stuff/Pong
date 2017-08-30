#include "gamefield.h"

GameField::GameField(QWidget *parent) : QWidget(parent) {

    grdGameLayout = new QGridLayout(this);
    grphGameView = new QGraphicsView(this);
    grphGameScene = new QGraphicsScene(grphGameView);


}



~GameField::GameField(){
    delete grdGameLayout;
    delete grphGameView;
    delete grphGameScene;
}

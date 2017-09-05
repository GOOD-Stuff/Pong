#include "gamefield.h"

GameField::GameField(QWidget *parent) : QWidget(parent) {

    grdGameLayout = new QGridLayout(this);
    grphGameView = new QGraphicsView(this);
    grphGameScene = new QGraphicsScene(grphGameView);

    btnStart = new QPushButton("Start", this);
    btnExit  = new QPushButton("Exit", this);
    btnReset = new QPushButton("Reset", this);

    connect(btnExit, SIGNAL(clicked(bool)), this, SLOT(close()));

    grdGameLayout->addWidget(grphGameView, 0, 0, 1, 3);
    grdGameLayout->addWidget(btnStart, 1, 0);
    grdGameLayout->addWidget(btnReset, 1, 1);
    grdGameLayout->addWidget(btnExit, 1, 2);

    this->setLayout(grdGameLayout);
    GamePlay();
}

void GameField::GamePlay(){
}

GameField::~GameField(){
    delete grdGameLayout;
    delete grphGameView;
    delete grphGameScene;
}

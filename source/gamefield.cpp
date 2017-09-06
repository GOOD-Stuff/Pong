#include "gamefield.h"

GameField::GameField(QWidget *parent) : QWidget(parent) {

    grdGameLayout = new QGridLayout(this);
    grphGameView = new QGraphicsView(this);
    grphGameScene = new QGraphicsScene(grphGameView);

    btnStart = new QPushButton("Start", this);
    btnStop  = new QPushButton("Stop", this);
    btnExit  = new QPushButton("Exit", this);
    btnReset = new QPushButton("Reset", this);

    gameTimer = new QTimer();

    connect(btnStart,  SIGNAL(clicked(bool)), this, SLOT(slotGameStart()));
    connect(btnStop,   SIGNAL(clicked(bool)), this, SLOT(slotGameStop()));
    connect(btnReset,  SIGNAL(clicked(bool)), this, SLOT(slotResetField()));
    connect(btnExit,   SIGNAL(clicked(bool)), this, SLOT(slotExitField()));
    connect(gameTimer, SIGNAL(timeout()),     this, SLOT(slotTimerCount()));

    btnStop->setHidden(true);

    grdGameLayout->addWidget(grphGameView, 0, 0, 1, 3);
    grdGameLayout->addWidget(btnStart, 1, 0);
    grdGameLayout->addWidget(btnStop,  1, 0);
    grdGameLayout->addWidget(btnReset, 1, 1);
    grdGameLayout->addWidget(btnExit,  1, 2);

    this->setLayout(grdGameLayout);

    x_step = grphGameView->height() / 2;
    y_step = grphGameView->width() / 2;
    x_direction = false;
    y_direction = false;
}

void GameField::GamePlay(){
    int const max_height = grphGameView->height();
    int const max_width = grphGameView->width();
    int const min_height = grphGameView->minimumHeight();
    int const min_width = grphGameView->minimumWidth();

    if(( y_step >= max_height ) || ( y_step <= min_height ))
        y_direction = !y_direction;
    if(( x_step >= max_width ) || ( x_step <= min_width ))
        x_direction = !x_direction;

    if( y_direction == false )
        y_step++;
    else if( y_direction == true )
        y_step--;

    if( x_direction == false )
        x_step++;
    else if( x_direction == true )
        x_step--;

        /*
        qDebug() << "X_step" << x_step;
        qDebug() << "Y_step" << y_step;
    */
    grphGameScene->addEllipse(-x_step, y_step, 30, 30, QPen(Qt::black), QBrush(Qt::blue));
    grphGameView->setScene(grphGameScene);
}

void GameField::slotTimerCount(){
    GamePlay();
}

void GameField::slotGameStop(){
    btnStart->setVisible(true);
    btnStop->setHidden(true);
    gameTimer->stop();

}

void GameField::slotGameStart(){
    btnStart->setHidden(true);
    btnStop->setVisible(true);
    gameTimer->start(1);
}

void GameField::slotResetField(){
    grphGameScene->clear();
    grphGameView->setScene(grphGameScene);
}

void GameField::slotExitField(){
    this->close();
}

GameField::~GameField(){
    delete grdGameLayout;
    delete grphGameView;
    delete grphGameScene;
}

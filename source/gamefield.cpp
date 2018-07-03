#include "gamefield.h"

GameField::GameField(QWidget *parent) : QWidget(parent) {
    grdGameLayout = new QGridLayout(this);
    grphGameView  = new QGraphicsView(this);
    grphGameScene = new QGraphicsScene(grphGameView);

    droo = new Drawer(grphGameView);
    plyr = new Player();

    btnStart  = new QPushButton("Start", this);
    btnStop   = new QPushButton("Stop", this);
    btnExit   = new QPushButton("Exit", this);
    btnReset  = new QPushButton("Reset", this);

    gameTimer = new QTimer();

    connect(btnStart,  SIGNAL(clicked(bool)), this, SLOT(slotGameStart()));
    connect(btnStop,   SIGNAL(clicked(bool)), this, SLOT(slotGameStop()));
    connect(btnReset,  SIGNAL(clicked(bool)), this, SLOT(slotResetField()));
    connect(btnExit,   SIGNAL(clicked(bool)), this, SLOT(slotExitField()));
    connect(this,      SIGNAL(Refresh()),           SLOT(slotRefreshField()));
    connect(gameTimer, SIGNAL(timeout()),     this, SLOT(slotTimerCount()));

    btnStop->setHidden(true);

    grdGameLayout->addWidget(grphGameView, 0, 0, 1, 3);
    grdGameLayout->addWidget(btnStart, 1, 0);
    grdGameLayout->addWidget(btnStop,  1, 0);
    grdGameLayout->addWidget(btnReset, 1, 1);
    grdGameLayout->addWidget(btnExit,  1, 2);

    this->setLayout(grdGameLayout);

    x_ball_step = grphGameView->height() / 2;
    y_ball_step = grphGameView->width() / 2;
    x_pos  = x_ball_step;
    y_pos  = y_ball_step;

    droo->SetBallPosition(x_ball_step, y_ball_step);

    x_direction = false;
    y_direction = false;
}

/**
 * @brief GameField::GamePlay
 */
void GameField::GamePlay(){
    emit Refresh();
    CalculatePos();

    grphGameScene->addItem(droo->DrawBall(/*-x_step, y_step*/));
    grphGameScene->addItem(droo->DrawPlayer());
//    grphGameScene->addItem(droo->DrawPlayer(-100, 50));
    grphGameView->setScene(grphGameScene);
}


/**
 * @brief
 * @param[in]
 *
 * @return none
 */
void GameField::keyPressEvent(QKeyEvent *event) {
    event->accept();
    int key = event->key();
    if (key == Qt::Key_A) {
        qDebug() << x_plyr_step;
        x_plyr_step--;
    }
    else if (key == Qt::Key_D) {
        qDebug() << x_plyr_step;
        x_plyr_step++;
    }
    if (key == Qt::Key_W) {
        qDebug() << y_plyr_step;
        y_plyr_step -= 5;
    }
    else if (key == Qt::Key_S) {
        qDebug() << y_plyr_step;
        y_plyr_step += 5;
    }
}


/**
 * @brief GameField::CalculatePos
 */
void GameField::CalculatePos(){
    int const max_height = grphGameView->height();
    int const max_width  = grphGameView->width();
    int const min_height = grphGameView->minimumHeight();
    int const min_width  = grphGameView->minimumWidth();

    if ((y_ball_step >= max_height) || (y_ball_step <= min_height))
        y_direction = !y_direction;
    if ((x_ball_step >= max_width) || (x_ball_step <= min_width))
        x_direction = !x_direction;

    if(y_direction == false)
        y_ball_step++;
    else if(y_direction == true)
        y_ball_step--;

    if (x_direction == false)
        x_ball_step++;
    else if (x_direction == true)
        x_ball_step--;

    droo->SetBallPosition(x_ball_step, y_ball_step);
    droo->SetPlayerPosition(x_plyr_step, y_plyr_step);

/*
    qDebug() << "max heir" << max_height;
    qDebug() << "X_step" << x_step;
    qDebug() << "Y_step" << y_step;
*/
}

/**
 * @brief GameField::slotTimerCount
 */
void GameField::slotTimerCount(){
    GamePlay();
}

/**
 * @brief GameField::slotGameStop
 */
void GameField::slotGameStop(){
    btnStart->setVisible(true);
    btnStop->setHidden(true);
    gameTimer->stop();

}

/**
 * @brief GameField::slotGameStart
 * @param none
 *
 * @return none
*/
void GameField::slotGameStart(){
    btnStart->setHidden(true);
    btnStop->setVisible(true);
    gameTimer->start(1);
}


void GameField::slotRefreshField() {
    grphGameScene->clear();
    grphGameView->setScene(grphGameScene);
}

/**
 * @brief GameField::slotResetField
 * @param none
 *
 * @return none
 */
void GameField::slotResetField(){
    grphGameScene->clear();

    x_ball_step = grphGameView->width()  / 2;
    y_ball_step = grphGameView->height() / 2;
    x_plyr_step = 50;
    y_plyr_step = 50;

    qDebug() << "X" << x_ball_step;
    qDebug() << "Y" << y_ball_step;

    qDebug() << "view_weight" << grphGameView->width();
    qDebug() << "view_height" << grphGameView->height();

    droo->SetBallPosition(x_ball_step, y_ball_step);
    droo->SetPlayerPosition(x_plyr_step, y_plyr_step);

    grphGameScene->addItem(droo->DrawBall(/*50, 50*/));
    grphGameScene->addItem(droo->DrawPlayer());
//    grphGameScene->addItem(droo->DrawPlayer(-100, 50));

    qDebug() << "weight" << grphGameScene->width();
    qDebug() << "height" << grphGameScene->height();

    grphGameView->setScene(grphGameScene);
}

/**
 * @brief GameField::slotExitField
 */
// TODO: SIGSEGV
void GameField::slotExitField(){
    //this->setHidden(true);
    this->close();
    this->destroy();
//    this->parentWidget()->show();
//    this->parentWidget()->setVisible(true);
}

GameField::~GameField(){
    delete droo;
    delete plyr;
    delete grdGameLayout;
    delete grphGameView;
    delete grphGameScene;
    delete gameTimer;
    delete btnExit;
    delete btnStart;
    delete btnStop;
    delete btnReset;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    widgMain  = new QWidget(this);
    game      = new GameField();
    settings  = new Settings();

    btnExt    = new QPushButton("Exit", this);
    btnMd1    = new QPushButton("Player vs CPU", this);
    btnMd2    = new QPushButton("Player vs Player", this);
    btnHlp    = new QPushButton("Help", this);
    btnSettng = new QPushButton("Settings", this);

   // grphView = new QGraphicsView(widgMain);
    //grphScene = new QGraphicsScene(grphView);
    connect(btnExt, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(btnMd1, SIGNAL(clicked(bool)), this, SLOT(slotSingleGame()));
    connect(btnMd2, SIGNAL(clicked(bool)), this, SLOT(slotNetwrkGame()));
    connect(btnHlp, SIGNAL(clicked(bool)), this, SLOT(slotHelpWidgt()));
   // connect(btnSettng, SIGNAL(clicked(bool)), this, SLOT(slotSettings()));
    connect(btnSettng, SIGNAL(clicked(bool)), settings, SLOT(show()));
    connect(game, SIGNAL(destroyed()), this, SLOT(raise()));

    grdLayout = new QGridLayout(widgMain);
    grdLayout->addWidget(btnMd1, 0, 0);
    grdLayout->addWidget(btnMd2, 0, 1);
    grdLayout->addWidget(btnHlp, 1, 0);
    grdLayout->addWidget(btnSettng, 1, 1);
    grdLayout->addWidget(btnExt, 2, 0, 2, 2);
//    grdLayout->addWidget(grphView, 1, 0, 1, 2);

    widgMain->setLayout(grdLayout);

    this->setWindowTitle("Pong v0.8");
    this->setMinimumHeight(30);
    this->setMinimumWidth(100);
    this->setCentralWidget(widgMain);
}


void MainWindow::slotSingleGame(){
//    this->setHidden(true);//hide();
    lower();
    emit game->show();
}

void MainWindow::slotNetwrkGame(){
    qDebug() << "stub";
}

void MainWindow::slotHelpWidgt(){
    qDebug() << "stub";
}

void MainWindow::slotSettings(){
    qDebug() << "stub";
}

MainWindow::~MainWindow(){
    delete ui;
    delete btnExt;
    delete btnMd1;
    delete btnMd2;
    delete btnHlp;
    delete btnSettng;
    delete game;
    delete grdLayout;
    delete widgMain;
}

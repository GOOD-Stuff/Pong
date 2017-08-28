#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    widgMain = new QWidget(this);

    btnOk  = new QPushButton("Ok", this);
    btnExt = new QPushButton("Exit", this);
    btnMd1 = new QPushButton("Player vs CPU", this);
    btnMd2 = new QPushButton("Player vs Player", this);
    btnHlp = new QPushButton("Help", this);
    btnSettng = new QPushButton("Settings", this);

    lne_name = new QLineEdit(this);
    lne_name->setText("Player1");
   // grphView = new QGraphicsView(widgMain);
    //grphScene = new QGraphicsScene(grphView);

    timer = new QTimer();

    connect(btnOk,  SIGNAL(clicked(bool)), this, SLOT(slotAcceptName()));
    connect(btnExt, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(btnMd1, SIGNAL(clicked(bool)), this, SLOT(slotSingleGame()));
    connect(btnMd2, SIGNAL(clicked(bool)), this, SLOT(slotNetwrkGame()));
    connect(btnHlp, SIGNAL(clicked(bool)), this, SLOT(slotHelpWidgt()));
    connect(btnSettng, SIGNAL(clicked(bool)), this, SLOT(slotSettings()));

    grdLayout = new QGridLayout(widgMain);
    grdLayout->addWidget(lne_name, 0, 0);
    grdLayout->addWidget(btnOk, 0, 1);
    grdLayout->addWidget(btnMd1, 1, 0);
    grdLayout->addWidget(btnMd2, 1, 1);
    grdLayout->addWidget(btnHlp, 3, 0);
    grdLayout->addWidget(btnSettng, 3, 1);
    grdLayout->addWidget(btnExt, 4, 0);
//    grdLayout->addWidget(grphView, 1, 0, 1, 2);

    widgMain->setLayout(grdLayout);

    this->setWindowTitle("Pong v0.7");
    this->setMinimumHeight(30);
    this->setMinimumWidth(100);
    this->setCentralWidget(widgMain);
}

void MainWindow::slotAcceptName(){
    Player player;
    player.set_plr_name(lne_name->text());
}

void MainWindow::slotSingleGame(){
    qDebug() << "stub";
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
    delete btnOk;
    delete btnExt;
    delete btnMd1;
    delete btnMd2;
    delete btnHlp;
    delete btnSettng;
    //delete grphScene;
//    delete grphView;
    delete grdLayout;
    delete widgMain;
    delete timer;
}

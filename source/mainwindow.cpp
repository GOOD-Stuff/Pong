#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    widgMain = new QWidget(this);

    btnOk  = new QPushButton("Ok", this);
    btnExt = new QPushButton("Exit", this);

    grphView = new QGraphicsView(widgMain);
    grphScene = new QGraphicsScene(grphView);

    timer = new QTimer();

    connect(btnOk, SIGNAL(clicked(bool)), this, SLOT(slotDrawClean()));
    connect(btnExt, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(timer, SIGNAL(timeout()), this, SLOT(slotDrawAnim()));

    grdLayout = new QGridLayout(widgMain);
    grdLayout->addWidget(btnOk, 0, 0);
    grdLayout->addWidget(btnExt, 0, 1);
    grdLayout->addWidget(grphView, 1, 0, 1, 2);

    widgMain->setLayout(grdLayout);

    this->setWindowTitle("Pong v0.1");
    this->setMinimumHeight(30);
    this->setMinimumWidth(100);
    this->setCentralWidget(widgMain);

    x_step = grphView->height() / 2;
    y_step = grphView->width() / 2;
    x_direction = false;
    y_direction = false;
    timer->start(10);
    //ui->setupUi(this);
}

void MainWindow::slotDrawClean(){
    grphScene->addEllipse(30, 100, 30, 30);
    grphView->setScene(grphScene);
}

void MainWindow::slotDrawAnim(){
    grphScene->clear();
    grphView->setScene(grphScene);

    int const max_height = grphView->height();
    int const max_width = grphView->width();
    int const min_height = grphView->minimumHeight();
    int const min_width = grphView->minimumWidth();

    qDebug() << "MAX: " << max_height;


    // TODO: need to reverse direction
    if(( y_step >= max_height ) || ( y_step <= min_height )){
        y_direction = !y_direction;
        qDebug() << y_direction;
    }
    if(( x_step >= max_width ) || ( x_step <= min_width )){
        x_direction = !x_direction;
        qDebug() << x_direction;
    }

    if( y_direction == false )
        y_step++;
    else if( y_direction == true )
        y_step--;

    if( x_direction == false )
        x_step++;
    else if( x_direction == true )
        x_step--;

    qDebug() << "X_step" << x_step;
    qDebug() << "Y_step" << y_step;

    grphScene->addEllipse(-x_step, y_step, 30, 30, QPen(Qt::black), QBrush(Qt::blue));
    grphView->setScene(grphScene);
}

MainWindow::~MainWindow(){
    delete ui;
    delete btnOk;
    delete btnExt;
    delete grphScene;
    delete grphView;
    delete grdLayout;
    delete widgMain;
}

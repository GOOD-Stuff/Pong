#include "drawer.h"

Drawer::Drawer(QWidget *parent) : QWidget(parent){
    grphDrawScene  = new QGraphicsScene(parent);
    grphDrawBall   = new QGraphicsEllipseItem();
    grphDrawPlayer = new QGraphicsRectItem();

    max_heigth  = parent->height();
    max_width   = parent->width();
    min_heigth  = parent->minimumHeight();
    min_width   = parent->minimumWidth();

    // TODO: set normal size calculation
    ball_radius = 3;
    ball_square = M_PI * pow(ball_radius, 2);

}

/**
 * @brief Drawer::DrawBall
 * @param x_step
 * @param y_step
 * @return
 */
QGraphicsItem *Drawer::DrawBall(int x_step, int y_step){
    grphDrawBall   = grphDrawScene->addEllipse(x_step, y_step, ball_square,
                                               ball_square, QPen(Qt::black),
                                               QBrush(Qt::blue));
    return grphDrawBall;
}

/**
 * @brief Drawer::DrawPlayer
 * @param x_step
 * @param y_step
 * @return
 */
// TODO: change size
QGraphicsItem *Drawer::DrawPlayer(int x_step, int y_step){
    grphDrawPlayer = grphDrawScene->addRect(x_step, y_step, ball_square,
                                            ball_square, QPen(Qt::black),
                                            QBrush(Qt::blue));
    return grphDrawPlayer;
}

Drawer::~Drawer(){
    delete grphDrawScene;
}

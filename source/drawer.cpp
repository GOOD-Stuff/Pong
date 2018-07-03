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

    x_ball_position = 0;
    y_ball_position = 0;
    x_ball_position = 0;
    y_ball_position = 0;

    rect_width  = 15;
    rect_length = 55;
}


/**
 * @brief
 * @param[in] x_pos
 * @param[in] y_pos
 *
 * @return
 */
void Drawer::SetBallPosition(int x_pos, int y_pos) {
    x_ball_position = x_pos;
    y_ball_position = y_pos;
}


/**
 * @brief
 * @param[in] x_pos
 * @param[in] y_pos
 *
 * @return none
 */
void Drawer::SetPlayerPosition(int x_pos, int y_pos) {
    x_playr_position = x_pos;
    y_playr_position = y_pos;
}

/**
 * @brief Drawer::DrawBall
 * @param x_step
 * @param y_step
 * @return
 */
QGraphicsItem *Drawer::DrawBall(/*int x_step, int y_step*/){
    grphDrawBall   = grphDrawScene->addEllipse(x_ball_position, y_ball_position, ball_square,
                                               //x_step, y_step, ball_square,
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
QGraphicsItem *Drawer::DrawPlayer(){
    grphDrawPlayer = grphDrawScene->addRect(x_playr_position, y_playr_position,
                                            rect_width, rect_length,
                                            QPen(Qt::black), QBrush(Qt::blue));
    return grphDrawPlayer;
}

Drawer::~Drawer(){
    delete grphDrawScene;
}

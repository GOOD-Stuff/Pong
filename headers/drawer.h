#ifndef DRAWER_H
#define DRAWER_H

/*
    This class responsible of drawing players and ball;
*/

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include <math.h>

class Drawer : public QWidget {
    Q_OBJECT
public:
    explicit Drawer(QWidget *parent = 0);

    QGraphicsItem *DrawBall(/*int x_step, int y_step*/);
    QGraphicsItem *DrawPlayer();
    void SetBallPosition(int x_pos, int y_pos);
    void SetPlayerPosition(int x_pos, int y_pos);
    void GetPosition(int &x_pos, int &y_pos);

    ~Drawer();
signals:

public slots:

private:
    int x_ball_position;
    int y_ball_position;
    int x_playr_position;
    int y_playr_position;

    int max_heigth;
    int max_width;
    int min_heigth;
    int min_width;
    int ball_square;
    int ball_radius;
    int rect_width;
    int rect_length;
    QGraphicsScene       *grphDrawScene;
    QGraphicsRectItem    *grphDrawPlayer;
    QGraphicsEllipseItem *grphDrawBall;
};

#endif // DRAWER_H

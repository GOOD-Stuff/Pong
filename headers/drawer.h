#ifndef DRAWER_H
#define DRAWER_H

/*
    This class responsible of drawing players and ball;
*/

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDebug>
#include <math.h>

class Drawer : public QWidget {
    Q_OBJECT
public:
    explicit Drawer(QWidget *parent = 0);
    QGraphicsItem *DrawBall(int x_step, int y_step);
    QGraphicsItem *DrawPlayer(int x_step, int y_step);
    ~Drawer();
signals:

public slots:

private:
    int max_heigth;
    int max_width;
    int min_heigth;
    int min_width;
    int ball_square;
    int ball_radius;
    int rect_square;
    QGraphicsScene       *grphDrawScene;
    QGraphicsRectItem    *grphDrawPlayer;
    QGraphicsEllipseItem *grphDrawBall;
};

#endif // DRAWER_H

#ifndef DRAWER_H
#define DRAWER_H

/*
    This class responsible of drawing players and ball;
*/

#include <QWidget>
#include <QGraphicsScene>


class Drawer : public QWidget {
    Q_OBJECT
public:
    explicit Drawer(QWidget *parent = 0);

signals:

public slots:
};

#endif // DRAWER_H

#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QWidget>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>

class GameField : public QWidget {
    Q_OBJECT
public:
    explicit GameField(QWidget *parent = 0);
    ~GameField();
signals:

public slots:

private:
    QGridLayout    *grdGameLayout;
    QGraphicsView  *grphGameView;
    QGraphicsScene *grphGameScene;
    QTimer         *gameTimer;
};

#endif // GAMEFIELD_H

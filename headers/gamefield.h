#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QWidget>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include "player.h"

class GameField : public QWidget {
    Q_OBJECT
public:
    explicit GameField(QWidget *parent = 0);
    void GamePlay();
    ~GameField();
signals:

public slots:

private:
    QGridLayout    *grdGameLayout;
    QGraphicsView  *grphGameView;
    QGraphicsScene *grphGameScene;
    QPushButton    *btnExit;
    QPushButton    *btnStart;
    QPushButton    *btnReset;
    QTimer         *gameTimer;
};

#endif // GAMEFIELD_H

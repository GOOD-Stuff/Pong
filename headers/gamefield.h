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

private slots:
    void slotResetField();
    void slotExitField();
    void slotGameStart();
    void slotGameStop();
    void slotTimerCount();

private:
    int y_step;
    int x_step;
    bool y_direction;
    bool x_direction;
    QGridLayout    *grdGameLayout;
    QGraphicsView  *grphGameView;
    QGraphicsScene *grphGameScene;
    QPushButton    *btnExit;
    QPushButton    *btnStart;
    QPushButton    *btnStop;
    QPushButton    *btnReset;    
    QTimer         *gameTimer;
};

#endif // GAMEFIELD_H

#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QWidget>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include <QMainWindow>
#include "player.h"
#include "drawer.h"

class GameField : public QWidget {
    Q_OBJECT
public:
    explicit GameField(QWidget *parent = 0);
    void GamePlay();
    ~GameField();
signals:
    void Refresh();

public slots:

private slots:
    void slotRefreshField();
    void slotResetField();
    void slotExitField();
    void slotGameStart();
    void slotGameStop();
    void slotTimerCount();

private:
    int            x_ball_step;
    int            y_ball_step;
    int            x_plyr_step;
    int            y_plyr_step;
    bool           x_direction;
    bool           y_direction;

    int            x_pos;
    int            y_pos;
    Drawer         *droo;
    Player         *plyr;
    QGridLayout    *grdGameLayout;
    QGraphicsView  *grphGameView;
    QGraphicsScene *grphGameScene;
    QPushButton    *btnExit;
    QPushButton    *btnStart;
    QPushButton    *btnStop;
    QPushButton    *btnReset;    
    QTimer         *gameTimer;
    void           CalculatePos();

protected:
    virtual void keyPressEvent(QKeyEvent *event);

};

#endif // GAMEFIELD_H

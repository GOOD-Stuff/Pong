#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <time.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void slotDrawReset(void);

private slots:
    void slotDrawAnim(void);

private:
    // fields
    Ui::MainWindow *ui;
    QWidget        *widgMain;
    QPushButton    *btnOk;
    QPushButton    *btnExt;
    QGridLayout    *grdLayout;
    QGraphicsView  *grphView;
    QGraphicsScene *grphScene;
    QTimer         *timer;
    int32_t         x_step;
    int32_t         y_step;
    bool            x_direction;
    bool            y_direction;
};

#endif // MAINWINDOW_H

/*
 *       Start menu
 * |-----------------------|
 * |--==Player===---Ok-----|
 * |-----------------------|
 * |---Player vs CPU ------|
 * |---Player vs Player ---|
 * |-----------------------|
 *
 *
 *      Some gameplay
 * |-----------------------|
 * |ooooooooooooooooooooooo|
 * |ooooooooooooooooooooooo|
 * |oo|--|ooo/***\ooo|--|oo|
 * |oo|  |oo|<-- |ooo|  |oo|
 * |oo|  |oo\**o/oooo|  |oo|
 * |oo|  |ooooooooooo|  |oo|
 * |oo|--|ooooooooooo|--|oo|
 * |ooooooooooooooooooooooo|
 * |ooooooooooooooooooooooo|
 * |_______________________|
 *
*/

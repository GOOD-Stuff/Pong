#ifndef PLAYER_H
#define PLAYER_H

/*
 * This class responsible of move and interact player with ball;
*/
#include <QObject>
#include <QDebug> // TODO: delete for release
#include <QString>
#include <QVector>
#include <QKeyEvent>
#include <QThread>

class Player : public QObject {
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);

//    void set_plr_name(QString name);
    QString get_plr_name(void);
    void Control();
    ~Player();
signals:
    void set_name(QString name);
public slots:
    void set_plr_name(QString name);
private:
    QString plr_name;
    QThread key_thread;
};

#endif // PLAYER_H

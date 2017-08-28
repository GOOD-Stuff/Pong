#ifndef PLAYER_H
#define PLAYER_H

/*
 * This class responsible of move and interact player with ball;
*/

#include <QDebug> // TODO: delete for release
#include <QString>
#include <QVector>
#include <QKeyEvent>

class Player {
public:
    Player();

    void set_plr_name(QString name);
    QString get_plr_name(void);

    ~Player();

private:
    QString plr_name;

};

#endif // PLAYER_H

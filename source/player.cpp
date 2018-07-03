#include "player.h"

Player::Player(QObject *parent) : QObject(parent) {
    plr_name = "";
    //connect(this, SIGNAL(set_name(QString)), this, SLOT(set_plr_name(QString)));
}

void Player::set_plr_name(QString name){
//    memccpy(&plr_name, &name, '\0', name.length());
    plr_name = name;
    qDebug() << plr_name;
}

QString Player::get_plr_name(){
    return plr_name;
}

void Player::Control(){
    for(int i = 0; i < 1000; i++) {}
}


Player::~Player(){
    plr_name.clear();
}

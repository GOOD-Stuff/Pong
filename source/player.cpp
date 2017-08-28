#include "player.h"

Player::Player() {

}

void Player::set_plr_name(QString name){
//    memccpy(&plr_name, &name, '\0', name.length());
    plr_name.clear();
    for( int i = 0; i < name.length(); i++ ){
        plr_name.append(name.at(i));
    }
}

QString Player::get_plr_name(){
    return plr_name;
}

Player::~Player(){

}

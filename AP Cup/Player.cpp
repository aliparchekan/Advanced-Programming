//
//  Player.cpp
//  
//
//  Created by Ali Parchekani on 11/12/17.
//

#include "Player.hpp"

using namespace std;

Player::Player(string _name, int _power , string _position) {
    set_name(_name);
    set_power(_power);
    set_position(_position);
    set_status(false);
}

void Player::set_name(string _name) {
    name = _name;
}

void Player::set_power(int _power) {
    if (_power < 0 || _power > 100)
        abort();
    power = _power;
}

void Player::set_position(string _position) {
    if ((_position != "midfielder") && (_position != "defender" ) && (_position != "goalkeeper" ) && (_position != "striker"))
        abort();
    position = _position;
}

void Player::set_status(bool _status) {
    status = _status;
}



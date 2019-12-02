//
//  Player.hpp
//  
//
//  Created by Ali Parchekani on 11/12/17.
//

#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Player {
public:
    Player(string _name, int _power , string _position);
    void set_name(string _name);
    void set_power(int _power);
    void set_position(string _position);
    void set_status (bool _status);
    string get_name() { return name;}
    int get_power() const { return power;}
    string get_position() { return position;}
    bool get_status() {return status;}
private:
    string name;
    int power;
    string position;
    bool status;
    
};

#endif /* Player_hpp */

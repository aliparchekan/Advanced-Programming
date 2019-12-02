//
//  Stadium.cpp
//  
//
//  Created by Ali Parchekani on 11/12/17.
//

#include "Stadium.hpp"

using namespace std;

Stadium::Stadium(string _name, int _capacity , float _impact) {
    set_name(_name);
    set_capacity(_capacity);
    set_impact(_impact);
}

void Stadium::set_name (string _name) {
    name = _name;
}

void Stadium::set_capacity (int _capacity) {
    if (_capacity < 0)
        abort();
    capacity = _capacity;
}

void Stadium::set_impact (float _impact) {
    impact = _impact;
}








//
//  Stadium.hpp
//  
//
//  Created by Ali Parchekani on 11/12/17.
//

#ifndef Stadium_hpp
#define Stadium_hpp


#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

class Stadium {
public:
    Stadium(string _name, int _capacity , float _impact);
    void set_name (string _name);
    void set_capacity (int _capacity);
    void set_impact (float _impact);
    string get_name () { return name;}
    int get_capacity() {return capacity;}
    float get_impact() {return impact;}
private:
    string name;
    int capacity;
    float impact;
};

#endif /* Stadium_hpp */

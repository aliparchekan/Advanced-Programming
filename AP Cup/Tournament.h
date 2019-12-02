//
//  Tournament.hpp
//  
//
//  Created by Ali Parchekani on 11/12/17.
//

#ifndef Tournament_hpp
#define Tournament_hpp

#include <iostream>
#include <string>
#include "Simulation.hpp"

class Simulation;

using namespace std;

class Tournament {
public:
    Tournament();
    void add_team(string _team_name , string _stadium_name , int _capacity , float _impact , map<string, int> _fans_in_stadium);
    void add_player(string _team_name , string _player_name , int _player_power , string _player_post);
    void simulate();
    void print_round_results(int round_number);
    void print_tournament_results();
    void print_team_results(string _team_name);
private:
    Simulation sim;
};

#endif /* Tournament_hpp */

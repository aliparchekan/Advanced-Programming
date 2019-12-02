//
//  Simulation.hpp
//  
//
//  Created by Ali Parchekani on 11/15/17.
//

#ifndef Simulation_hpp
#define Simulation_hpp

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Team.hpp"
#include "Round.hpp"

class Team;
class Round;

#define NOT_FOUND -1

class Simulation {
public:
    Simulation();
    void add_team(string _team_name , string _stadium_name , int _capacity , float _impact , map<string, int> _fans_in_stadium);
    void add_player(string _team_name , string _player_name , int _player_power , string _player_post);
    void check_teams();
    void simulate();
    void print_round_results(int round_number);
    void print_tournament_results();
    void print_team_results(string _team_name);
    void generate_teams_to_rounds();
    void check_num_of_teams();
    int index_of_team_finder(string _team_name);
private:
    vector<Team> teams_in_tournament;
    vector<Round> rounds_in_tournament;
    vector<Team*> teams_to_rounds;
};

#endif /* Simulation_hpp */

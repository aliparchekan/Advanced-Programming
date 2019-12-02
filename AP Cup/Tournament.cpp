//
//  Tournament.cpp
//  
//
//  Created by Ali Parchekani on 11/12/17.
//

#include "Tournament.h"

Tournament::Tournament(){}

void Tournament::add_team(string _team_name , string _stadium_name , int _capacity , float _impact , map<string, int> _fans_in_stadium) {
    sim.add_team(_team_name , _stadium_name , _capacity , _impact , _fans_in_stadium);
}

void Tournament::add_player(string _team_name , string _player_name , int _player_power , string _player_post) {
    sim.add_player(_team_name , _player_name , _player_power , _player_post);
}

void Tournament::simulate() {
    sim.simulate();
}

void Tournament::print_round_results(int round_number) {
    sim.print_round_results(round_number);
}

void Tournament::print_tournament_results() {
    sim.print_tournament_results();
}

void Tournament::print_team_results(string _team_name) {
    sim.print_team_results(_team_name);
}

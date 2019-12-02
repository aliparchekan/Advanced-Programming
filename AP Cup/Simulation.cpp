//
//  Simulation.cpp
//  
//
//  Created by Ali Parchekani on 11/15/17.
//

#include "Simulation.hpp"
Simulation::Simulation() {
}

void Simulation::add_team(string _team_name , string _stadium_name , int _capacity , float _impact , map<string, int> _fans_in_stadium) {
    teams_in_tournament.push_back(Team(_team_name , _stadium_name , _capacity , _impact , _fans_in_stadium));
}

int Simulation::index_of_team_finder(string _team_name) {
    for (int i = 0; i < teams_in_tournament.size() ; i++ ) {
        if (teams_in_tournament[i].get_teams_name() == _team_name) {
            return i;
        }
    }
    return NOT_FOUND;
}

void Simulation::add_player(string _team_name , string _player_name , int _player_power , string _player_post) {
    int index = index_of_team_finder(_team_name);
    if (index == NOT_FOUND) {
        abort();
    }
    teams_in_tournament[index].add_player(_player_name , _player_power , _player_post);
}

void Simulation::check_teams() {
    for (int i = 0; i < teams_in_tournament.size() ; i++ ) {
        if (!teams_in_tournament[i].is_team_valid()) {
            teams_in_tournament[i].set_participating_status(false);
            cout << "Inadequate players in " << teams_in_tournament[i].get_teams_name() << endl;
        }
    }
}

void Simulation::generate_teams_to_rounds() {
    check_teams();
    for (int i = 0; i < teams_in_tournament.size() ; i++ ) {
        if (teams_in_tournament[i].give_participating_status() == true) {
            teams_to_rounds.push_back(&teams_in_tournament[i]);
        }
    }
}

void Simulation::check_num_of_teams() {
    int n = teams_to_rounds.size();
    if ( n == 0) {
        cout << "Inadequate teams" << endl;
        abort();
    }
    if ((n & (n - 1)) != 0) {
        cout << "Inadequate teams" << endl;
        abort();
    }
}

void Simulation::simulate(){
    generate_teams_to_rounds();
    check_num_of_teams();
    rounds_in_tournament.push_back(Round(teams_to_rounds , 1));
    rounds_in_tournament[0].create_matches();
    int i = 0;
    while (true) {
        if (rounds_in_tournament[i].is_last_round()) {
            break;
        }
        rounds_in_tournament.push_back(Round(rounds_in_tournament[i].teams_advancing_next_round() , i + 2));
        rounds_in_tournament[i+1].create_matches();
        i++;
    }
    
}

void Simulation::print_tournament_results() {
    for (int i = 0; i < rounds_in_tournament.size() ; i++ ) {
        cout << "Round " << i + 1 << endl;
        rounds_in_tournament[i].print_round();
    }
}

void Simulation::print_round_results(int round_number) {
    cout << "Round " << round_number << endl;
    rounds_in_tournament[round_number - 1].print_round();
}

void Simulation::print_team_results(string _team_name) {
    for (int i = 0; i < rounds_in_tournament.size() ; i++ ) {
        if (rounds_in_tournament[i].is_team_in_round(_team_name)) {
            cout << "Round " << i + 1 << endl;
            int index = rounds_in_tournament[i].find_team_match_index(_team_name);
            rounds_in_tournament[i].print_this_match(index);
            continue;
        }
        break;
    }
//    int index = index_of_team_finder(_team_name);
//    if (index == NOT_FOUND) {
//        abort();
//    }
//    vector<int> round_of_team = teams_in_tournament[index].round_numbers();
//    vector<int> match_of_team = teams_in_tournament[index].match_numbers();
//    cout << "hello" << round_of_team.size() << match_of_team.size() << endl;
//    cout << round_of_team[0] << endl;
//    return;
//    for (int i = 0; i < round_of_team.size() ; i++ ) {
//        cout << round_of_team[i] << endl;
//        cout << match_of_team[i] << endl;
//        rounds_in_tournament[round_of_team[i] - 1].print_this_match(match_of_team[i] - 1);
//    }
}



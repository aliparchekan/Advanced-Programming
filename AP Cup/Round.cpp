//
//  Round.cpp
//  
//
//  Created by Ali Parchekani on 11/14/17.
//

#include "Round.hpp"

Round::Round(vector<Team*> _teams_this_round , int i){
    teams_this_round = _teams_this_round;
    round_number = i;
}

bool team_sorter (Team* const& first , Team* const& last) {
    return first->get_teams_name() < last->get_teams_name();
}

void Round::sort_round() {
    sort(teams_this_round.begin() , teams_this_round.end() , &team_sorter);
}

void Round::create_matches() {
    sort_round();
    int k = 1;
    for (int i = 0; i < teams_this_round.size() ; i = i + 2 ) {
        matches_this_round.push_back(Match(teams_this_round[i],teams_this_round[i + 1] , round_number , k));
        k++;
    }
}

vector<Team*> Round::teams_advancing_next_round() {
    vector<Team*> result;
    for (int i = 0 ; i < matches_this_round.size() ; i++ ) {
        result.push_back(matches_this_round[i].run_match());
    }
    return result;
}

bool Round::is_last_round() {
    vector<Team*> result = teams_advancing_next_round();
    if (result.size() == 1) {
        return true;
    }
    return false;
}

void Round::print_round() {
    for (int i = 0; i < matches_this_round.size() ; i++ ) {
        cout << i + 1 << ":" << endl;
        matches_this_round[i].print_match();
    }
}

bool Round::is_team_in_round(string _team_name) {
    for (int i = 0; i < teams_this_round.size() ; i++ ) {
        if (teams_this_round[i]->get_teams_name() == _team_name) {
            return true;
        }
    }
    return false;
}

int Round::find_team_match_index (string _team_name) {
    for (int i = 0; i < matches_this_round.size() ; i++ ) {
        Team* first = matches_this_round[i].get_first_team();
        Team* second = matches_this_round[i].get_second_team();
        if ((first->get_teams_name() == _team_name ) || (second->get_teams_name() == _team_name)) {
            return i;
        }
    }
    return NOT_FOUND;
}

void Round::print_this_match(int index) {
    cout << index + 1 << ":" << endl;
    matches_this_round[index].print_match();
}
//int main() {
//    Team ali("perspolis" , "azadi" , 100000 , 1.0 );
//    Team ati("esteghlal" , "azadi" , 2 ,1.0);
//    vector<Team*> a;
//    a.push_back(&ali);
//    a.push_back(&ati);
//    Round r(a);
//    r.sort_round();
//    r.print();
//
//}


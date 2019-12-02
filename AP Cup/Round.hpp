//
//  Round.hpp
//  
//
//  Created by Ali Parchekani on 11/14/17.
//

#ifndef Round_hpp
#define Round_hpp

#include <iostream>
#include <vector>
#include "Match.hpp"

#define NOT_FOUND -1

class Match;

class Round {
public:
    Round(vector<Team*> _teams_this_round , int i);
    void sort_round();
    void create_matches();
    vector<Team*> teams_advancing_next_round();
    bool is_last_round();
    void print_round();
    void print_this_match(int index);
    bool is_team_in_round(string _team_name);
    int find_team_match_index (string _team_name);
private:
    vector<Team*> teams_this_round;
    vector<Match> matches_this_round;
    int round_number;
};

#endif /* Round_hpp */

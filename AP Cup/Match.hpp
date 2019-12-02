//
//  Match.hpp
//  
//
//  Created by Ali Parchekani on 11/14/17.
//

#ifndef Match_hpp
#define Match_hpp

#include <iostream>
#include "Game.hpp"
#include "Team.hpp"

class Game;
class Team;

class Match {
public:
    Match(Team* _home , Team* _away , int i , int k);
    void Determine_winner();
    void penalty_time();
    Team* run_match();
    void print_match();
    Team* get_first_team() {return first_team;}
    Team* get_second_team() {return second_team;}
private:
    Game first_leg;
    Game second_leg;
    Team* first_team;
    Team* second_team;
    Team* winner;
    int round_number;
};

#endif /* Match_hpp */

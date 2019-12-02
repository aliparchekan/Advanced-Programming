//
//  Game.hpp
//  
//
//  Created by Ali Parchekani on 11/12/17.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "Team.hpp"
#include <cmath>

using namespace std;

class Team;

class Game {
public:
    Game(Team* _home , Team* _away , int i , int k);
    float calculate_home_fan_impact();
    float calculate_away_fan_impact();
    float calculate_home_def();
    float calculate_away_def();
    float calculate_home_mid();
    float calculate_away_mid();
    float calculate_home_attack();
    float calculate_away_attack();
    int get_round_number() {return round_number;}
    int get_match_number() {return match_number;}
    int home_goals();
    int away_goals();
    private:
    Team* home;
    Team* away;
    int round_number;
    int match_number;
};

#endif /* Game_hpp */

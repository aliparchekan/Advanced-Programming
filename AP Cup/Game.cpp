//
//  Game.cpp
//  
//
//  Created by Ali Parchekani on 11/12/17.
//

#include "Game.hpp"

Game::Game(Team* _home , Team* _away , int i , int k){
    home = _home;
    away = _away;
    round_number = i;
    match_number = k;
}

float Game::calculate_home_fan_impact() {
    float home_audiances = (float)(home->get_fans_in_stadium(home->get_teams_stadium_name()));
    float away_audiances = (float)(away->get_fans_in_stadium(home->get_teams_stadium_name()));
    float cap = (float)(home->get_stadium_size());
    float im = home->get_stadium_impact();
    if (home_audiances > cap) {
        return im;
    }
    return im * (home_audiances / cap);
}

float Game::calculate_away_fan_impact() {
    float home_audiances = (float)(home->get_fans_in_stadium(home->get_teams_stadium_name()));
    float away_audiances = (float)(away->get_fans_in_stadium(home->get_teams_stadium_name()));
    float cap = (float)(home->get_stadium_size());
    float im = home->get_stadium_impact();
    if (home_audiances + away_audiances > cap) {
        away_audiances = cap - home_audiances;
    }
    return im * (away_audiances / cap);
}


float Game::calculate_home_def() {
//    cout<<"bb";
//    if (home->get_teams_name() == "Real Madrid") {
//        cout << "def of real = " << home->get_defend_power() << endl;
//    }
    return home->get_defend_power() + calculate_home_fan_impact();
    
}

float Game::calculate_away_def() {
    return away->get_defend_power() + calculate_away_fan_impact();
}

float Game::calculate_home_mid() {
    return home->get_midfield_power() + calculate_home_fan_impact();
}

float Game::calculate_away_mid() {
    return away->get_midfield_power() + calculate_away_fan_impact();
}

float Game::calculate_home_attack() {
    return home->get_strike_power() + calculate_home_fan_impact();
}

float Game::calculate_away_attack() {
    return away->get_strike_power() + calculate_away_fan_impact();
}

int Game::home_goals() {
    float num = calculate_home_attack() * calculate_home_mid();
    float den = calculate_away_def() * calculate_away_mid();
    float result = num / den;
    return floor(3 * result * sqrt(result));
}

int Game::away_goals() {
    float num = calculate_away_attack() * calculate_away_mid();
    float den = calculate_home_def() * calculate_home_mid();
    float result = num / den;
    return floor(3 * result * sqrt(result));
}



//int main() {
//    cout << "hello" << endl;
//    return 0;
//}




//
//  Match.cpp
//  
//
//  Created by Ali Parchekani on 11/14/17.
//

#include "Match.hpp"

Match::Match(Team* _home , Team* _away , int i , int k) : first_leg(_home,_away, i ,k ) , second_leg(_away,_home , i , k ) , first_team(_home) , second_team(_away) {
    _home->add_to_games(&first_leg);
    _home->add_to_games(&second_leg);
    _away->add_to_games(&first_leg);
    _away->add_to_games(&second_leg);
    round_number = i;
}

void Match::Determine_winner() {
    int first_teams_home_goals = first_leg.home_goals();
    int second_teams_away_goals = first_leg.away_goals();
    int first_teams_away_goals = second_leg.away_goals();
    int second_teams_home_goals = second_leg.home_goals();
    if (first_teams_home_goals + first_teams_away_goals > second_teams_home_goals + second_teams_away_goals) {
        second_team->set_participating_status(false);
        winner = first_team;
        return;
    }
    if (first_teams_home_goals + first_teams_away_goals < second_teams_home_goals + second_teams_away_goals) {
        first_team->set_participating_status(false);
        winner = second_team;
        return;
    }
    if (first_teams_away_goals > second_teams_away_goals) {
        second_team->set_participating_status(false);
        winner = first_team;
        return;
    }
    if (first_teams_away_goals < second_teams_away_goals) {
        first_team->set_participating_status(false);
        winner = second_team;
        return;
    }
    penalty_time();
}

void Match::penalty_time() {
    float prob1 = (first_team->get_strike_power()) / (second_team->get_keeper_power());
    float prob2 = (second_team -> get_strike_power()) / (first_team->get_keeper_power());
    if (prob1 > prob2) {
        second_team->set_participating_status(false);
        winner = first_team;
        return;
    }
    first_team->set_participating_status(false);
    winner = second_team;
    return;
}

Team* Match::run_match() {
    Determine_winner();
    return winner;
}

void Match::print_match() {
    cout << '\t' << first_team->get_teams_name() << ' ' << first_leg.home_goals() << " - " << first_leg.away_goals() << ' ' << second_team->get_teams_name() << endl;
    cout << '\t' << second_team->get_teams_name() << ' ' << second_leg.home_goals() << " - " << second_leg.away_goals() << ' ' << first_team->get_teams_name() << endl;
    cout << '\t' << "=> winner: " << winner->get_teams_name() << endl;
}

//int main() {
//    Team ali("perspolis" , "azadi" , 100000 , 1.0 );
//    Team ati("perspolis" , "azadi" , 100000 , 1.0 );
//
//    cout << "hello " << endl;
//}


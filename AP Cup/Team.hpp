//
//  Team.hpp
//  
//
//  Created by Ali Parchekani on 11/12/17.
//

#ifndef Team_hpp
#define Team_hpp

#include <iostream>
#include "Player.hpp"
#include "Stadium.hpp"
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Game.hpp"


#define KEEPER "goalkeeper"
#define DEF "defender"
#define MID "midfielder"
#define STRIKE "striker"


class Player;
class Stadium;
class Game;

class Team {
public:
    Team(string _team_name , string _stadium_name , int _capacity , float _impact , map<string , int> _fans_in_stadium);
    void add_player(string _player_name , int _power , string _player_position);
    bool is_team_valid();
    void sort_team();
    vector<Player> squad_generator();
    float get_defend_power();
    float get_midfield_power();
    float get_strike_power();
    float get_teams_stadium_impact();
    float get_keeper_power();
    float get_stadium_impact();
    void set_participating_status(bool state);
    bool give_participating_status();
    string get_teams_stadium_name();
    int get_stadium_size();
    string get_teams_name() const {return name;}
    void add_to_games(Game* _games);
    int get_fans_in_stadium (string stadium_match);
    string last_person(){return players[players.size() - 1].get_name(); }
   // void print_team();
    vector<int> round_numbers();
    vector<int> match_numbers();
private:
    string name;
    Stadium teams_stadium;
    map<string, int> fans_in_stadium;
    bool participating;
    vector<Player> players;
    vector<Game*> games;
};


#endif /* Team_hpp */

//
//  Team.cpp
//  
//
//  Created by Ali Parchekani on 11/12/17.
//

#include "Team.hpp"


using namespace std;

Team::Team(string _team_name , string _stadium_name , int _capacity , float _impact , map<string, int> _fans_in_stadium)
        : teams_stadium(_stadium_name , _capacity , _impact){
            name = _team_name;
            participating = true;
            fans_in_stadium = _fans_in_stadium;
}

void Team::add_player(string _player_name , int _power , string _player_position) {
    Player temp(_player_name , _power , _player_position);
    players.push_back(temp);
}

bool Team::is_team_valid() {
    if (players.size() < 11) {
        return false;
    }
    int mid_count = 0 , def_count = 0 , strike_count = 0 , goal_count = 0;
    for (int i = 0; i < players.size() ; i++ ) {
        if (players[i].get_position() == "goalkeeper") {
            goal_count++;
            continue;
        }
        if (players[i].get_position() == "defender") {
            def_count++;
            continue;
        }
        if (players[i].get_position() == "midfielder") {
            mid_count++;
            continue;
        }
        if (players[i].get_position() == "striker") {
            strike_count++;
            continue;
        }
    }
    if ((goal_count < 1) || (def_count < 3) || (mid_count < 3) || (strike_count < 2)) {
        return false;
    }
    return true;
}

bool player_sorter(Player const& first , Player const& last) {
    return first.get_power() > last.get_power();
}

void Team::sort_team() {
    sort(players.begin() , players.end() , &player_sorter);
}

vector<Player> Team::squad_generator() {
    vector<Player> squad;
    sort_team();
    int goal_count = 1;
    int strike_count = 2;
    int mid_count = 3;
    int def_count = 3;
    for (int i = 0; i < players.size() ; i++ ) {
        if ((players[i].get_position() == "goalkeeper") && (goal_count > 0)) {
            squad.push_back(players[i]);
            goal_count--;
            players[i].set_status(true);
            continue;
        }
        if ((players[i].get_position() == "defender") && (def_count > 0)) {
            squad.push_back(players[i]);
            def_count--;
            players[i].set_status(true);
            continue;
        }
        if ((players[i].get_position() == "midfielder") && (mid_count > 0)) {
            squad.push_back(players[i]);
            mid_count--;
            players[i].set_status(true);
            continue;
        }
        if ((players[i].get_position() == "striker") && (strike_count > 0)) {
            squad.push_back(players[i]);
            strike_count--;
            players[i].set_status(true);
            continue;
        }
    }
    for (int i = 0; i < players.size() ; i++ ) {
        if (squad.size() == 11)
            break;
        if ((players[i].get_status() == false) && (players[i].get_position() != "goalkeeper")) {
            squad.push_back(players[i]);
        }
    }
    for (int i = 0; i < players.size() ; i++) {
        players[i].set_status(false);
    }
    return squad;
}

//void Team::print_team() {
//    for (int i = 0; i < games.size() ; i = i + 2 ) {
//        cout << "Round " << games[i].get_round_number() << endl;
//        cout << games[i].get_match_number() << ":" << endl;
//        cout << '\t' << games[i]->give_home_name() << ' ' << games[i]->home_goals() << " - " << games[i].away_goals() << ' ' << games[i]->give_away_name() << endl;
//        cout << '\t' << games[i + 1]->give_home_name() << ' ' << games[i + 1]->home_goals() << " - " << games[i + 1].away_goals() << ' ' <<
//                        games[i + 1]->give_away_name() << endl;
//    }
//}

float Team::get_defend_power() {
    int keeper_power = 0;
    int defenders_power = 0;
    int num_of_defenders = 0;
    vector<Player> squad = squad_generator();
    for (int i = 0; i < squad.size() ; i++ ) {
        if (squad[i].get_position() == "defender" ) {
            num_of_defenders++;
            defenders_power += squad[i].get_power();
            continue;
        }
        if (squad[i].get_position() == "goalkeeper") {
            keeper_power = squad[i].get_power();
        }
    }
    float num = (keeper_power + defenders_power)  * sqrt((float)num_of_defenders / 4);
    float den = (((float)num_of_defenders + 1));
    return floor(num/den);
}

float Team::get_keeper_power() {
    vector<Player> squad = squad_generator();
    for (int i = 0; i < squad.size() ; i++) {
        if (squad[i].get_position() == KEEPER) {
            return (float)squad[i].get_power();
        }
    }
    return 0;
}

float Team::get_midfield_power() {
    int mid_power = 0;
    int num_of_midfielders = 0;
    vector<Player> squad = squad_generator();
    for (int i = 0; i < squad.size() ; i++ ) {
        if (squad[i].get_position() == MID) {
            num_of_midfielders++;
            mid_power += squad[i].get_power();
            continue;
        }
    }
    float num = ((float) mid_power) * sqrt((float)num_of_midfielders / 3);
    float den = (((float)num_of_midfielders ));
    return floor(num/den);
}

float Team::get_strike_power() {
    int strike_power = 0;
    int num_of_strikers = 0;
    vector<Player> squad = squad_generator();
    for (int i = 0; i < squad.size() ; i++ ) {
        if (squad[i].get_position() == STRIKE) {
            num_of_strikers++;
            strike_power += squad[i].get_power();
            continue;
        }
    }
    float num = ((float) strike_power) * sqrt(((float)num_of_strikers / 3));
    float den = (((float)num_of_strikers)) ;
    return floor(num/den);
}

float Team::get_teams_stadium_impact() {
    return teams_stadium.get_impact();
}

string Team::get_teams_stadium_name() {
    return teams_stadium.get_name();
}

void Team::set_participating_status(bool state) {
    participating = state;
}

bool Team::give_participating_status() {
    return participating;
}

void Team::add_to_games(Game* _games) {
    games.push_back(_games);
}

int Team::get_fans_in_stadium (string stadium_match) {
    return fans_in_stadium[stadium_match];
}

int Team::get_stadium_size() {
    return teams_stadium.get_capacity();
}

float Team::get_stadium_impact() {
    return teams_stadium.get_impact();
}

vector<int> Team::round_numbers() {
    vector<int> result;
    for (int i = 0; i < games.size() ; i = i + 2 ) {
        result.push_back(games[i]->get_round_number());
    }
    return result;
}

vector<int> Team::match_numbers() {
    vector<int> result;
    for (int i = 0; i < games.size() ; i = i + 2 ) {
        result.push_back(games[i]->get_match_number());
    }
    return result;
}




//int main() {
//    Team ali("perspolis" , "azadi" , 100000 , 1.0 );
//    ali.add_player("ali" , 90 , "goalkeeper");
//    ali.add_player("ati" , 100 , "striker");
//    ali.add_player("erfan" , 2 , "midfielder");
//    ali.add_player("soghrat" , 3 , "defender");
//    ali.add_player("alim" , 84 , "defender");
//    ali.add_player("atim" , 99 , "defender");
//    ali.add_player("farhikhte" , 2 , "midfielder");
//    ali.add_player("sag" , 3 , "midfielder");
//    ali.add_player("alibb" , 9 , "midfielder");
//    ali.add_player("atibb" , 10 , "striker");
//    ali.add_player("erfanss" , 20 , "goalkeeper");
//    ali.add_player("soghratff" , 30 , "striker");
//    vector<Player> players = ali.squad_generator();
//    ali.get_strike_power();
//    for (int i = 0; i < players.size() ; i++ ) {
//        cout << players[i].get_name() << '\t';
//        cout << players[i].get_power() << '\t';
//        cout << players[i].get_position() << endl;
//    }
////    ali.sort_team();
////    ali.print();
//    return 0;
//}

















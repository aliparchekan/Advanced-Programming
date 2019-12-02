//
//  music_place.hpp
//  
//
//  Created by Ali Parchekani on 12/28/17.
//

#ifndef music_place_hpp
#define music_place_hpp

#include <iostream>
#include "places.hpp"

class places;
class music;
class user;

class music_place : public places
{
public:
	music_place(user* a , music* b , Database* c ) : places(a) , current(b) , main_data(c) {}
	void goToArtist() {}
	string get_going_artist() {return getArtist();}
	string get_going_album(){return getAlbum();}
	void goToAlbum(){}
	void rate(int score);
	string getArtist();
	string getAlbum();
	int getLength();
	string getName();
	string getCompleteName();
	int getRate();
	int getUserRate();
	bool addTo(string target);
	int getCriticRate();
	void validate_item();
	vector<music*> play();
private:
	music* current;
	Database* main_data;
};

#include "music.hpp"
#include "user.hpp"


#endif /* music_place_hpp */

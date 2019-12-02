//
//  album_place.hpp
//  
//
//  Created by Ali Parchekani on 12/28/17.
//

#ifndef album_place_hpp
#define album_place_hpp

#include <iostream>
#include "places.hpp"
#include "album.hpp"

class places;
class album;
class user;
class music;

class album_place : public places
{
public:
	album_place(user* a , album* b , Database* c) : places(a) , current(b) , main_data(c) {}
	string get_going_artist() {return getArtist();}
	void goToArtist() {}
	List list();
	List listMusics();
	bool addTo(string target);
	void remove(string music_name);
	void rate(int score);
	int getLength();
	string getArtist();
	string getName();
	string getCompleteName();
	int getRate();
	int getUserRate();
	int getCriticRate();
	void validate_item();
	vector<music*> play();
private:
	album* current;
	Database* main_data;
};

#endif /* album_place_hpp */

//
//  artist_place.hpp
//  
//
//  Created by Ali Parchekani on 12/29/17.
//

#ifndef artist_place_hpp
#define artist_place_hpp

#include <iostream>
#include "places.hpp"
#include "artist.hpp"
#include "user.hpp"
#include "Database.hpp"


class places;
class artist;
class user;
class Database;


class artist_place : public places
{
public:
	artist_place(user* a , artist* b , Database* c): places(a) , current(b) , main_data(c) {}
	List list();
	List listMusics();
	List listAlbums();
	string getName();
	string getCompleteName();
	void rate(int score);
	int getRate();
	int getUserRate();
	int getCriticRate();
	vector<music*> play();
private:
	artist* current;
	Database* main_data;
};

#endif /* artist_place_hpp */

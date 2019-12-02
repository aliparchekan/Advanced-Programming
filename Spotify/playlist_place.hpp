//
//  playlist_place.hpp
//  
//
//  Created by Ali Parchekani on 12/28/17.
//

#ifndef playlist_place_hpp
#define playlist_place_hpp

#include <iostream>
#include "places.hpp"
#include "user.hpp"
#include "playlist.hpp"

class places;
class user;
class playlist;

class playlist_place:public places {
public:
	playlist_place(user* a , playlist* b) : places(a) , current(b) {}
	List list();
	List listMusics();
	List listAlbums();
	void remove(string music_name);
	void orderItem (string music_name , int new_order);
	int getLength();
	string getName();
	string getCompleteName();
	vector<music*> play();
private:
	playlist* current;
};

#endif /* playlist_place_hpp */

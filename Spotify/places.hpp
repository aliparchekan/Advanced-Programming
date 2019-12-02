//
//  places.hpp
//  
//
//  Created by Ali Parchekani on 12/25/17.
//

#ifndef places_hpp
#define places_hpp

#include <iostream>
#include "api.hpp"
#include "exceptions.hpp"

using namespace std;

class user;
class music;

class places {
public:
	places(user* my):place_user(my){}
	virtual void goToPlaylists();
	virtual void goToLibrary();
	virtual void goToArtist();
	virtual vector<music*> play();
	virtual string get_going_artist(){return "";}
	virtual string get_going_album(){return "";}
	//virtual void goToMusic();
	virtual void goToAlbum();
	virtual List list();
	virtual List listMusics();
	virtual List listAlbums();
	virtual List listPlaylists();
	virtual List listArtists();
	virtual bool addTo(string target);
	//bayad hazf she goto
	virtual void goTo(string playlist_name) {}
	virtual void remove(string music_name) {}
	virtual void orderItem (string music_name , int new_order) {}
	virtual void rate(int score);
	virtual string getArtist();
	virtual string getAlbum();
	virtual int getLength();
	//BEPORS
	virtual string getName();
	virtual string getCompleteName();
	virtual int getRate();
	virtual int getUserRate();
	virtual int getCriticRate();
	virtual void validate_item();
	bool is_not_listed(const List& result , string name);
protected:
	user* place_user;

};

#include "user.hpp"
#include "music.hpp"

#endif /* places_hpp */

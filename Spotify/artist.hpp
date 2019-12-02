//
//  artist.hpp
//  
//
//  Created by Ali Parchekani on 12/30/17.
//

#ifndef artist_hpp
#define artist_hpp

#include <iostream>
#include "user.hpp"
#include "gerdabify_element.hpp"
#include "api.hpp"

class user;
class gerdabify_element;
class Database;
class album;
class music;

class artist :public user , public gerdabify_element {
public:
	artist(string fname , string lname , string uname , string password , UserType Artist , Database* a) :
			 user(fname , lname , uname , password , Artist , a) , gerdabify_element(uname) {}
	string getArtist();
	string getAlbum();
	int getLength();
	string getCompleteName();
	void addMusic(string music_name, string music_file_path);
	void addAlbum(string artist_name, string album_name);
	vector<music*> get_musics();
	vector<album*> get_albums();
	virtual UserType get_user_type() { return Artist;}
private:		
	vector<album*> artists_album;
};

#include "Database.hpp"
#include "album.hpp"
#include "music.hpp"

#endif /* artist_hpp */

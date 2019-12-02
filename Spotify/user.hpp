//
//  user.hpp
//  
//
//  Created by Ali Parchekani on 12/24/17.
//

#ifndef user_hpp
#define user_hpp

#include <iostream>
#include <vector>
#include "api.hpp"


using namespace std;

// typedef vector<string> List;

// enum UserType {Admin, Artist, Editor, Normal};

// struct UserData
// {
//     string firstname;
//     string lastname;
//     string username;
//     UserType userType;
// };

class places;
class Database;
class queue;
class home;
class library;
class music;
class playlists;
class playlist;
class artist_place;
class music_place;
class album_place;
class playlist_place;
class queue_place;

class user {
public:
	user(string _first_name , string _last_name , string _user_name , string _password , UserType _type , Database* a);
	void enterBrowserMode();
	void goTohome();
	void goToPlaylists();
	void goToLibrary();
	void goToArtist();
	//void goToMusic();
	void goToAlbum();
	List search (string target);
	void select(string target);
	List list();
	List listMusics();
	List listAlbums();
	List listPlaylists();
	List listArtists();
	void addTo(string target);
	void goTo(string playlist_name);
	void createPlaylist(string playlist_name);
	void clearPlaylist(string playlist_name);
	void remove(string music_name);
	void orderItem (string music_name , int new_order);
	void rate(int score);
	string getArtist();
	string getAlbum();
	int getLength();
	string getName();
	string get_user_name();
	string getCompleteName();
	virtual UserType get_user_type() = 0;
	int getRate();
	int getUserRate();
	int getCriticRate();
	virtual void validate_item();
	virtual void addMusic(string music_name, string music_file_path);
	virtual void addAlbum(string artist_name, string album_name);
	virtual void verifyUser(string username);
	void get_verified() {verified = true;}
	bool is_verified() {return verified;}
	void is_browsing();
	bool is_password_correct(string pass);
	UserData getUserDetails(string userName);
	void play();
	void enterPlayerMode();
	void is_player();
	void next();
	void previous();
	void pause();
	void shuffle();
	void repeat();
	void repeatOne();
	List get_user_playlists();
protected:
	string first_name;
	string last_name;
	string user_name;
	string password;
	places* current_place;
	vector<music*> users_music;
	vector<playlist*> users_playlist;
	bool browsing;
	bool player;
	Database* main_data;
	queue* users_queue;
	UserType type;
	bool verified;
};

#include "places.hpp"
#include "Database.hpp"
#include "music.hpp"
#include "home.hpp"
#include "library.hpp"
#include "playlists.hpp"
#include "playlist.hpp"
#include "artist_place.hpp"
#include "music_place.hpp"
#include "album_place.hpp"
#include "playlist_place.hpp"
#include "queue.hpp"
#include "queue_place.hpp"


#endif /* user_hpp */

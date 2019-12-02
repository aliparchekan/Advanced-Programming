//
//  Database.hpp
//  
//
//  Created by Ali Parchekani on 12/30/17.
//

#ifndef Database_hpp
#define Database_hpp

#include <iostream>
#include <string>
#include <vector>
#include "api.hpp"

using namespace std;

class user;
class album;
class music;
class playlist;
class artist;
class normal;
class admin;
class editor;

class Database {
public:
	Database();
	music* get_music(string music_name);
	album* get_album(string album_name);
	user* get_user(string user_name);
	artist* get_artist(string user_name);
	vector<music*> get_musics();
	vector<album*> get_albums();
	vector<music*>* get_musics_address() {return &all_musics;}
	playlist* get_playlist(string playlist_name);
	void search_music(string name , List& result);
	void search_album(string name , List& result);
	void search_artist(string name , List& result);
	void search_playlist(string name , List& result);
	void add_music(music* temp);
	void add_album(album* temp);
	void add_playlist(playlist* temp);


	void enterBrowserMode();
	void goTohome();
	void goToPlaylists();
	void goToLibrary();
	void goToArtist();
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
	int getRate();
	int getUserRate();
	int getCriticRate();
	void validate();
	void addMusic(string music_name, string music_file_path);
	void addAlbum(string artist_name, string album_name);
	void verifyUser(string username);
	UserData getUserDetails(string userName);
	void signup(UserData user_info , string password);
	void login(string userName , string password);
	List search_all_music();
	List search_all_albums();
	List search_all_artists();
	List get_currents_playlists();
	
	void enterPlayerMode();
	void play();
	void next();
	void previous();
	void pause();
	void shuffle();
	void repeat();
	void repeatOne();
private:
	vector<user*> all_users;
	vector<album*> all_albums;
	vector<music*> all_musics;
	vector<playlist*> all_playlists;
	user* current;
};

#include "user.hpp"
#include "album.hpp"
#include "music.hpp"
#include "artist.hpp"
#include "admin.hpp"
#include "editor.hpp"
#include "normal.hpp"


#endif /* Database_hpp */

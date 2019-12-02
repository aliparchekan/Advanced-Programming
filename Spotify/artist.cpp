//
//  artist.cpp
//  
//
//  Created by Ali Parchekani on 12/30/17.
//

#include "artist.hpp"

using namespace std;

string artist::getArtist() {
	return user_name;
}

string artist::getAlbum() {
	throw MethodNotAvaliable();
}

int artist::getLength() {
	throw MethodNotAvaliable();
}

string artist::getCompleteName() {
	return user_name;
}

void artist::addMusic(string music_name, string music_file_path) {
	if (!this->is_verified())
	{
		throw NotAuthorized();
	}
	music* exist = main_data->get_music(music_name);
	if (exist != NULL)
	{
		throw AlreadyExists();
	}
	music* new_music = new music(music_name , music_file_path , this);
	main_data -> add_music(new_music);
	users_music.push_back(new_music);
}

void artist::addAlbum(string artist_name, string album_name) {
	if (!this->is_verified())
	{
		throw NotAuthorized();
	}
	album* exist = main_data->get_album(album_name);
	if (exist != NULL)
	{
		throw AlreadyExists();
	}
	album* new_album = new album(album_name,this);
	main_data->add_album(new_album);
	artists_album.push_back(new_album);
}

vector<music*> artist::get_musics() {
	return users_music;
}

vector<album*> artist::get_albums() {
	return artists_album;
}








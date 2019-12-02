//
//  music.cpp
//  
//
//  Created by Ali Parchekani on 12/23/17.
//

#include "music.hpp"

using namespace std;

music::music(string _name , string _file_path , artist* _music_artist) : gerdabify_element(_name) {
	file_path = _file_path;
	music_artist = _music_artist;
	music_album = NULL;
}

string music::getArtist() {
	return music_artist->get_user_name();
}

string music::getAlbum() {
	if (music_album == NULL)
	{
		cout << "album not specified" << endl;
		return "";
	}
	return music_album->getName();
}

int music::getLength() {
	return 0;
}

string music::getCompleteName() {
	if (music_album == NULL)
	{
		return "album not specified";
	}
	string temp = "";
	temp += music_album->getCompleteName();
	temp += "-";
	temp += getName();
	return temp;
}

void music::set_album(album* _music_album) {
	music_album = _music_album;
}

string music::get_music_path() {
	return file_path;
}
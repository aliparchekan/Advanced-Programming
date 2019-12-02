//
//  album.cpp
//  
//
//  Created by Ali Parchekani on 12/24/17.
//

#include "album.hpp"

using namespace std;

album::album(string _name , artist* _album_artist) : gerdabify_element(_name) {
	album_artist = _album_artist;
}

void album::add_music(music* _music) {
	musics_in_album.push_back(_music);
}

string album::getArtist() {
	return album_artist->get_user_name();
}

string album::getAlbum() {
	return getName();
}

int album::getLength() {
	int result = 0;
	for (int i = 0; i < musics_in_album.size(); ++i)
	{
		result += musics_in_album[i]->getLength();
	}
	return result;
}

string album::getCompleteName() {
	string result = "";
	result += album_artist->get_user_name();
	result += "-";
	result += getName();
	return result;
}

void album::remove(string music_name) {
	int index = find_music_index(music_name);
	if (index == NOT_FOUND)
	{
		throw ItemDoesNotExist();
	}
	vector<music*> result;
	for (int i = 0; i < index; ++i)
	{
		result.push_back(musics_in_album[i]);
	}
	for (int i = index + 1; i < musics_in_album.size(); ++i)
	{
		result.push_back(musics_in_album[i]);
	}
	musics_in_album.clear();
	musics_in_album = result;
}

int album::find_music_index(string music_name) {
	for (int i = 0; i < musics_in_album.size(); ++i)
	{
		if (musics_in_album[i]->getName() == music_name)
		{
			return i;
		}
	}
	return NOT_FOUND;
}







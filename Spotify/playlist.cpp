//
//  playlist.cpp
//  
//
//  Created by Ali Parchekani on 12/24/17.
//

#include "playlist.hpp"

using namespace std;

playlist::playlist(string _name , user* _creator) : gerdabify_element(_name) , creator(_creator) {
}

void playlist::clearPlayList() {
	musics_in_playlist.clear();
}

int playlist::find_music_index(string music_name) {
	for (int i = 0; i < musics_in_playlist.size(); ++i)
	{
		if (musics_in_playlist[i]->getName() == music_name)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

void playlist::remove(string music_name) {
	int index = find_music_index(music_name);
	if (index == NOT_FOUND)
	{
		throw ItemDoesNotExist();
	}
	vector<music*> result;
	for (int i = 0; i < index; ++i)
	{
		result.push_back(musics_in_playlist[i]);
	}
	for (int i = index + 1; i < musics_in_playlist.size(); ++i)
	{
		result.push_back(musics_in_playlist[i]);
	}
	clearPlayList();
	musics_in_playlist = result;
}

void playlist::orderItem(string music_name , int newOrder) {
	int index = find_music_index(music_name);
	if (index == NOT_FOUND)
	{
		throw ItemDoesNotExist();
	}
	if ((newOrder > musics_in_playlist.size() )||( (newOrder < 1)))
	{
		throw InvalidArguments();
	}
	vector<music*> result;
	music* current = musics_in_playlist[index];
	remove(music_name);
	for (int i = 0; i < newOrder - 1; ++i)
	{
		result.push_back(musics_in_playlist[i]);
	}
	result.push_back(current);
	for (int i = newOrder - 1; i < musics_in_playlist.size(); ++i)
	{
		result.push_back(musics_in_playlist[i]);
	}
	clearPlayList();
	musics_in_playlist = result;
}

string playlist::getArtist() {
	throw MethodNotAvaliable();
}

string playlist::getAlbum() {
	throw MethodNotAvaliable();
}

int playlist::getLength() {
	int result = 0;
	for (int i = 0; i < musics_in_playlist.size(); ++i)
	{
		result += musics_in_playlist[i] -> getLength();
	}
	return result;
}

string playlist::getCompleteName(){
	string temp = "";
	temp += creator->get_user_name();
	temp += "-";
	temp += getName();
	return temp;
}

int playlist::getRate(string user_name) { return 0;}
int playlist::getUserRate() {return 0;}
int playlist::getCriticRate() {return 0;}
void playlist::rate(user* new_user , int rate){}

void playlist::add_music(music* _music) {
	musics_in_playlist.push_back(_music);
}






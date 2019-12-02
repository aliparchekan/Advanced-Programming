//
//  album_place.cpp
//  
//
//  Created by Ali Parchekani on 12/28/17.
//

#include "album_place.hpp"

using namespace std;

List album_place::list() {
	List result;
	vector<music*> musics = current->get_album_musics();
	for (int i = 0; i < musics.size(); ++i)
	{
		if (musics[i]->is_validated())
		{
			result.push_back(musics[i]->getName());
		}
	}
	return result;
}

List album_place::listMusics() {
	return list();
}

bool album_place::addTo(string target) {
	if (target == "queue")
	{
		return false;
	}
	playlist* dest_play = main_data->get_playlist(target);
	album* dest_album = main_data->get_album(target);
	if (dest_album != NULL)
	{
		if (dest_album->getArtist() != place_user->get_user_name())
		{
			throw NotAuthorized();
		}
		vector<music*> musics = current -> get_album_musics();
		for (int i = 0; i < musics.size(); ++i)
		{
			dest_album->add_music(musics[i]);
		}
		return true;
	}
	if (dest_play != NULL)
	{
		if (dest_play->get_creator_user_name() != place_user->get_user_name())
		{
			throw NotAuthorized();
		}
		vector<music*> musics = current -> get_album_musics();
		for (int i = 0; i < musics.size(); ++i)
		{
			dest_play->add_music(musics[i]);
		}
		return true;
	}
	throw ItemDoesNotExist();
}

void album_place::remove(string music_name) {
	if (place_user->get_user_name() != current->getArtist())
	{
		throw NotAuthorized();
	}
	current->remove(music_name);
}

void album_place::rate(int score) {
	current->rate(place_user,score);
}

string album_place::getArtist() {
	return current->getArtist();
}

int album_place::getLength() {
	return current->getLength();
}

string album_place::getName() {
	return current->getName();
}

string album_place::getCompleteName() {
	return current-> getCompleteName();
}

int album_place::getRate() {
	return current->getRate(place_user->get_user_name());
}

int album_place::getUserRate() {
	return current->getUserRate();
}

int album_place::getCriticRate() {
	return current->getCriticRate();
}

void album_place::validate_item() {
	current->validate();
}

vector<music*> album_place::play() {
	return current->get_album_musics();
}




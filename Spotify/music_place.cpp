//
//  music_place.cpp
//  
//
//  Created by Ali Parchekani on 12/28/17.
//

#include "music_place.hpp"

using namespace std;

void music_place::rate(int score) {
	current->rate(place_user,score);
}

string music_place::getArtist() {
	return current->getArtist();
}

string music_place::getAlbum() {
	return current->getAlbum();
}

int music_place::getLength() {
	return current->getLength();
}

string music_place::getName() {
	return current->getName();
}

string music_place::getCompleteName() {
	return current->getCompleteName();
}

int music_place::getRate() {
	return current->getRate(place_user->get_user_name());
}

int music_place::getUserRate() {
	return current->getUserRate();
}

int music_place::getCriticRate() {
	return current->getCriticRate();
}

void music_place::validate_item() {
	return current->validate();
}

bool music_place::addTo(string target) {
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
		dest_album->add_music(current);
		current->set_album(dest_album);
		return true;
	}
	if (dest_play != NULL)
	{
		if (dest_play->get_creator_user_name() != place_user->get_user_name())
		{
			throw NotAuthorized();
		}
		dest_play->add_music(current);
		return true;
	}
	throw ItemDoesNotExist();
}

vector<music*> music_place::play() {
	vector<music*> result;
	result.push_back(current);
	return result;
}










//
//  playlist_place.cpp
//  
//
//  Created by Ali Parchekani on 12/28/17.
//

#include "playlist_place.hpp"


using namespace std;

List playlist_place::list() {
	List result;
	vector<music*> musics = current->get_musics();
	for (int i = 0; i < musics.size(); ++i)
	{
		result.push_back(musics[i]->getName());
	}
	return result;
}

List playlist_place::listMusics() {
	return list();
}

List playlist_place::listAlbums() {
	List result;
	vector<music*> musics = current->get_musics();
	for (int i = 0; i < musics.size(); ++i)
	{
		if (is_not_listed(result , musics[i]->getAlbum()))
		{
			result.push_back(musics[i]->getAlbum());
		}
	}
	return result;
}

void playlist_place::remove(string music_name) {
	if (place_user->get_user_name() != current->get_creator_user_name())
	{
		throw NotAuthorized();
	}
	current->remove(music_name);
}

void playlist_place::orderItem (string music_name , int new_order) {
	current->orderItem(music_name,new_order);
}

int playlist_place::getLength() {
	return current->getLength();
}

string playlist_place::getName() {
	return current->getName();
}

string playlist_place::getCompleteName() {
	return current->getCompleteName();
}

vector<music*> playlist_place::play() {
	return current->get_musics();
}



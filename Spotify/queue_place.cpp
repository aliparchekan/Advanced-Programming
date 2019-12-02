//
//  queue_place.cpp
//  
//
//  Created by Ali Parchekani on 12/30/17.
//

#include "queue_place.hpp"


List queue_place::list() {
	List result;
	vector<music*> musics = current->get_musics();
	for (int i = 0; i < musics.size(); ++i)
	{
		result.push_back(musics[i]->getName());
	}
	return result;
}

List queue_place::listMusics() {
	return list();
}

List queue_place::listAlbums() {
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

void queue_place::remove(string music_name) {
	if (place_user->get_user_name() != current->get_creator_user_name())
	{
		throw NotAuthorized();
	}
	current->remove(music_name);
}

void queue_place::orderItem (string music_name , int new_order) {
	current->orderItem(music_name,new_order);
}


vector<music*> queue_place::play() {
	vector<music*> result;
	return result;
}












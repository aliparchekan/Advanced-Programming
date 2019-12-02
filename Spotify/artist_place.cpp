//
//  artist_place.cpp
//  
//
//  Created by Ali Parchekani on 12/29/17.
//

#include "artist_place.hpp"

using namespace std;


List artist_place::list() {
	vector<music*> musics = current->get_musics();
	List result;
	if (place_user -> get_user_name() == current -> get_user_name())
	{
		for (int i = 0; i < musics.size(); ++i)
		{
			result.push_back(musics[i]->getName());
		}
		return result;
	}
	for (int i = 0; i < musics.size(); ++i)
	{
		if (musics[i]->is_validated())
		{
			result.push_back(musics[i]->getName());
		}
	}
	return result;
}

List artist_place::listMusics() {
	return list();
}

List artist_place::listAlbums() {
	vector<album*> albums = current -> get_albums();
	List result;
	if (place_user->get_user_name() == current-> get_user_name())
	{
		for (int i = 0; i < albums.size(); ++i)
		{
			result.push_back(albums[i]->getName());
		}
		return result;
	}
	for (int i = 0; i < albums.size(); ++i)
	{
		if (albums[i]->is_validated())
		{
			result.push_back(albums[i]->getName());
		}
	}
	return result;	
}

string artist_place::getName() {
	return current->get_user_name();
}

string artist_place::getCompleteName() {
	return current->get_user_name();
}

void artist_place::rate(int score) {
	current->gerdabify_element::rate(place_user,score);
}

int artist_place::getRate() {
	return current->gerdabify_element::getRate(place_user->get_user_name());
 }

 int artist_place::getUserRate() {
 	return current->gerdabify_element::getUserRate();
 }

int artist_place::getCriticRate() {
	return current->gerdabify_element::getCriticRate();
}

vector<music*> artist_place::play() {
	return current->get_musics();
}














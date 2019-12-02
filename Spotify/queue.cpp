//
//  queue.cpp
//  
//
//  Created by Ali Parchekani on 12/30/17.
//

#include "queue.hpp"

queue::queue(user* _creator) : creator(_creator) {
	player = new GerdabPlayer();
	previous_music = NULL;
	repeat_music = false;
	repeat_one = false;
	shuffle_music = false;
}

void queue::add_front(music* temp) {
	vector<music*> result;
	result.push_back(temp);
	for (int i = 0; i < musics_in_queue.size(); ++i)
	{
		result.push_back(musics_in_queue[i]);
	}
	musics_in_queue.clear();
	musics_in_queue = result;
}

void queue::remove(string music_name) {
	int index = find_music_index(music_name);
	if (index == NOT_FOUND)
	{
		throw ItemDoesNotExist();
	}
	vector<music*> result;
	for (int i = 0; i < index; ++i)
	{
		result.push_back(musics_in_queue[i]);
	}
	for (int i = index + 1; i < musics_in_queue.size(); ++i)
	{
		result.push_back(musics_in_queue[i]);
	}
	musics_in_queue.clear();
	musics_in_queue = result;
}

void queue::orderItem(string music_name , int newOrder) {
	int index = find_music_index(music_name);
	if (index == NOT_FOUND)
	{
		throw ItemDoesNotExist();
	}
	if ((newOrder > musics_in_queue.size() )||( (newOrder < 1)))
	{
		throw InvalidArguments();
	}
	vector<music*> result;
	music* current = musics_in_queue[index];
	remove(music_name);
	for (int i = 0; i < newOrder - 1; ++i)
	{
		result.push_back(musics_in_queue[i]);
	}
	result.push_back(current);
	for (int i = newOrder - 1; i < musics_in_queue.size(); ++i)
	{
		result.push_back(musics_in_queue[i]);
	}
	musics_in_queue.clear();
	musics_in_queue = result;
}

int queue::find_music_index(string music_name) {
	for (int i = 0; i < musics_in_queue.size(); ++i)
	{
		if (musics_in_queue[i]->getName() == music_name)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

void queue::remove_played() {
	vector<music*> result;
	for (int i = 1; i < musics_in_queue.size(); ++i)
	{
		result.push_back(musics_in_queue[i]);
	}
	previous_music = musics_in_queue[0];
	musics_in_queue.clear();
	musics_in_queue = result;
}

void queue::repeat_played() {
	vector<music*> result;
	for (int i = 0; i < musics_in_queue.size(); ++i)
	{
		result.push_back(musics_in_queue[i]);
	}
	previous_music = musics_in_queue[0];
	result.push_back(musics_in_queue[0]);
	musics_in_queue.clear();
	musics_in_queue = result;
}

void queue::play() {
	int index;
	if (shuffle_music)
	{
		index = rand() / musics_in_queue.size();
	} else {
		index = 0;
	}
	if (musics_in_queue.size() == 0)
	{
		cout << "no song in queue" << endl;
		return;
	}
	cout << musics_in_queue[index]->get_music_path() << endl;
	player->setMusic(musics_in_queue[index]->get_music_path());
	player->play();
	if (repeat_music)
	{
		repeat_played();
		return;
	}
	if(!repeat_one && !shuffle_music) {
		remove_played();
		return;
	}
}

void queue::next() {
	if (repeat_music)
	{	
		repeat_played();
		play();
		return;
	}
	if (repeat_one)
	{
		play();
		return;
	}
	remove_played();
	return;
}

void queue::previous() {
	if (previous_music == NULL)
	{
		cout << "no previous music" << endl;
		return;
	}
	add_front(previous_music);
	play();
}

void queue::pause() {
	player->pause();
}

void queue::shuffle() {
	shuffle_music = ! shuffle_music;
}

void queue::repeat() {
	repeat_music = !repeat_music;
}

void queue::repeatOne() {
	repeat_one = !repeat_one;
}




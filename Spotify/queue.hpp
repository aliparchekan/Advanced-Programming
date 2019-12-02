//
//  queue.hpp
//  
//
//  Created by Ali Parchekani on 12/30/17.
//

#ifndef queue_hpp
#define queue_hpp

#include <iostream>
#include "user.hpp"
#include "music.hpp"
#include "sdlHeaders.hpp"
#include "gerdabPlayer.hpp"

#define NOT_FOUND -1

class user;
class music;
class gerdabPlayer;

class queue 
{
public:
	queue(user* _creator);
	void add_front(music* temp);
	void add_music(music* _music) {musics_in_queue.push_back(_music);}
	vector<music*> get_musics() {return musics_in_queue;}
	string get_creator_user_name() {return creator->get_user_name();}
	void remove(string music_name);
	void orderItem(string music_name , int newOrder);
	int find_music_index(string music_name);
	void play();
	void remove_played();
	void next();
	void repeat_played();
	void previous();
	void pause();
	void shuffle();
	void repeat();
	void repeatOne();
private:
	vector<music*> musics_in_queue;
	user* creator;
	GerdabPlayer* player;
	music* previous_music;
	bool repeat_music;
	bool repeat_one;
	bool shuffle_music;
	
};

#endif /* queue_hpp */

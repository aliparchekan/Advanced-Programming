//
//  playlist.hpp
//  
//
//  Created by Ali Parchekani on 12/24/17.
//

#ifndef playlist_hpp
#define playlist_hpp

#include <iostream>
#include "gerdabify_element.hpp"
#include "music.hpp"
#include "exceptions.hpp"

#define NOT_FOUND -1

class music;
class gerdabify_element;

class playlist : public gerdabify_element {
public:
	playlist(string _name , user* _creator);
	void clearPlayList();
	void add_music(music* _music);
	void remove(string music_name);
	int find_music_index(string music_name);
	void orderItem(string music_name , int newOrder);
	vector<music*> get_musics() {return musics_in_playlist;}
	string get_creator_user_name() {return creator->get_user_name();}
	string getArtist();
    string getAlbum();
    int getLength();
    string getCompleteName();
    int getRate(string user_name);
    int getUserRate();
    int getCriticRate();
    void rate(user* new_user , int rate);
private:
	vector<music*> musics_in_playlist;
	user* creator;
};


#endif /* playlist_hpp */

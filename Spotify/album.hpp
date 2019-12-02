//
//  album.hpp
//  
//
//  Created by Ali Parchekani on 12/24/17.
//

#ifndef album_hpp
#define album_hpp

#include <iostream>
#include <string>
#include <vector>
#include "gerdabify_element.hpp"

#define NOT_FOUND -1

class artist;
class music;
class gerdabify_element;

class album : public gerdabify_element {
public:
	album(string _name , artist* _album_artist);
	void add_music(music* _music);
	vector<music*> get_album_musics() {return musics_in_album;}
	virtual string getArtist();
    virtual string getAlbum();
    virtual int getLength();
    virtual string getCompleteName();
    void remove(string music_name);
    int find_music_index(string music_name);
private:
	vector<music*> musics_in_album;
	artist* album_artist;
};


#include "music.hpp"
#include "artist.hpp"

#endif /* album_hpp */

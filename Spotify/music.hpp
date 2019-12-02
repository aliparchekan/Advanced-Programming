//
//  music.hpp
//  
//
//  Created by Ali Parchekani on 12/23/17.
//

#ifndef music_hpp
#define music_hpp

#include <iostream>
#include "gerdabify_element.hpp"

using namespace std;

class artist;
class album;
class gerdabify_element;

class music : public gerdabify_element {
public:
	music(string _name , string _file_path , artist* _music_artist);
	void set_album(album* _music_album);
	virtual string getArtist();
    virtual string getAlbum();
    virtual int getLength();
    virtual string getCompleteName();
    string get_music_path();
private:
	album* music_album;
	artist* music_artist;
	string file_path;
};

#include "artist.hpp"
#include "album.hpp"

#endif /* music_hpp */

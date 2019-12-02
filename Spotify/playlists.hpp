//
//  playlists.hpp
//  
//
//  Created by Ali Parchekani on 12/28/17.
//

#ifndef playlists_hpp
#define playlists_hpp

#include <iostream>
#include "places.hpp"
#include "playlist.hpp"

class places;
class playlist;
class user;

class playlists : public places
{
public:
	playlists(user* a, vector<playlist*> b) : places(a) , users_playlist(b) {}
	virtual List list();
	virtual List listPlaylists();
private:
	vector<playlist*> users_playlist;
	
};

#include "user.hpp"

#endif /* playlists_hpp */

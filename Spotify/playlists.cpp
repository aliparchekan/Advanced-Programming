//
//  playlists.cpp
//  
//
//  Created by Ali Parchekani on 12/28/17.
//

#include "playlists.hpp"

using namespace std;

List playlists::list() {
	List result;
	for (int i = 0; i < users_playlist.size(); ++i)
	{
		result.push_back(users_playlist[i]->getName());
	}
	return result;
}

List playlists::listPlaylists() {
	return list();
}
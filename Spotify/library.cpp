//
//  library.cpp
//  
//
//  Created by Ali Parchekani on 12/28/17.
//

#include "library.hpp"

using namespace std;

List library::list() {
	vector<music*> musics_in_database;
	musics_in_database = main_data->get_musics();
	List result;
	for (int i = 0; i < musics_in_database.size(); ++i)
	{
		if (is_not_listed(result , musics_in_database[i]->getArtist()))
		{
			result.push_back(musics_in_database[i]->getArtist());
		}
	}
	return result;
}

List library::listMusics() {
	vector<music*> musics_in_database;
	musics_in_database = main_data->get_musics();
	List result;
	for (int i = 0; i < musics_in_database.size(); ++i)
	{
		result.push_back(musics_in_database[i]->getName());
	}
	return result;
}



List library::listAlbums() {
	vector<album*> albums_in_database;
	albums_in_database = main_data->get_albums();
	List result;
	for (int i = 0; i < albums_in_database.size(); ++i)
	{
		result.push_back(albums_in_database[i]->getName());
	}
	return result;
}

List library::listArtists() {
	return list();
}









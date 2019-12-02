//
//  user.cpp
//  
//
//  Created by Ali Parchekani on 12/24/17.
//

#include "user.hpp"

using namespace std;

user::user(string _first_name , string _last_name , string _user_name , string _password , UserType _type , Database* a) {
	first_name = _first_name;
	last_name = _last_name;
	user_name = _user_name;
	password = _password;
	browsing = false;
	main_data = a;
	current_place=NULL;
	player = false;
	users_queue = new queue(this);
	if ((_type == Normal || _type==Admin))
	{
		verified = true;
	} else {
		verified = false;
	}
}

void user::enterBrowserMode() {
	player = false;
	browsing = true;
}

void user::enterPlayerMode() {
	browsing = false;
	player = true;
}

void user::is_player() {
	if (!player)
	{
		throw MethodNotAvaliable();
	}
}
void user::is_browsing() {
	if (!browsing)
	{
		throw MethodNotAvaliable();
	}
}

void user::goTohome() {
	is_browsing();
	delete current_place;
	current_place = new home(this);
}

void user::goToPlaylists() {
	is_browsing();
	current_place->goToPlaylists();
	delete current_place;
	current_place = new playlists(this , users_playlist);
}

void user::goToLibrary() {
	is_browsing();
	current_place->goToLibrary();
	delete current_place;
	current_place= new library(main_data,this);
}

void user::goToArtist() {
	is_browsing();
	current_place->goToArtist();
	string artist_name = current_place->get_going_artist();
	artist* result = main_data->get_artist(artist_name);
	delete current_place;
	current_place = new artist_place(this , result , main_data);
}

void user::goToAlbum() {
	is_browsing();
	current_place->goToAlbum();
	string album_name = current_place->get_going_album();
	album* result = main_data->get_album(album_name);
	if ((!result->is_validated()) && (get_user_name() != result->getArtist()))
	{
		cout << "album has not been validated yet so can't be displayed" << endl;
		return;
	}
	delete current_place;
	current_place = new album_place(this , result,main_data);
}

List user::search (string target) {
	List result;
	main_data->search_music(target,result);
	main_data->search_album(target,result);
	main_data->search_artist(target,result);
	main_data->search_playlist(target,result);
	return result;
}

void user::select(string target) {
	music* selected_music = main_data->get_music(target);
	album* selected_album = main_data->get_album(target);
	artist* selected_artist = main_data->get_artist(target);
	playlist* selected_playlist = main_data->get_playlist(target);
	if (selected_music != NULL)
	{
		if ((!selected_music->is_validated()) && (get_user_name() != selected_music->getArtist()))
		{
			cout << "music has not been validated yet so can't be displayed" << endl;
			return;
		}
		delete current_place;
		current_place = new music_place(this , selected_music , main_data);
		return;
	}
	if (selected_album != NULL)
	{
		if ((!selected_album->is_validated()) && (get_user_name() != selected_album->getArtist()))
		{
			cout << "album has not been validated yet so can't be displayed" << endl;
			return;
		}
		delete current_place;
		current_place = new album_place(this , selected_album , main_data);
		return;
	}
	if (selected_artist != NULL)
	{
		if ((!selected_artist->is_verified()) && (get_user_name() != selected_artist->get_user_name()))
		{
			cout << "artist has not been verified yet so can't be displayed" << endl;
			return;
		}
		delete current_place;
		current_place = new artist_place(this , selected_artist , main_data);
		return;
	}
	if (selected_playlist != NULL)
	{
		// if ((!selected_playlist->is_validated()) && (get_user_name() != selected_playlist->get_creator_user_name()))
		// {
		// 	cout << "playlist has not been validated yet so can't be displayed" << endl;
		// 	return;
		// }
		delete current_place;
		current_place = new playlist_place(this , selected_playlist);
		return;
	}
	throw ItemDoesNotExist();
}

List user::list() {
	return current_place->list();
}

List user::listMusics() {
	return current_place->listMusics();
}

List user::listAlbums() {
	return current_place->listAlbums();
}

List user::listPlaylists() {
	return current_place->listPlaylists();
}

List user::listArtists() {
	return current_place->listArtists();
}

void user::addTo(string target) {
	bool temp = current_place->addTo(target);
	if (!temp)
	{
		vector<music*> result = current_place->play();
		for (int i = 0; i < result.size(); ++i)
		{
			users_queue->add_music(result[i]);
		}
	}
}

List user::get_user_playlists() {
	List result;
	for (int i = 0; i < users_playlist.size(); ++i)
	{
		result.push_back(users_playlist[i]->getName());
	}
	return result;
}

void user::goTo(string playlist_name) {
	if (playlist_name == "queue")
	{
		delete current_place;
		current_place = new queue_place(this,users_queue);
	}
	playlist* result = main_data->get_playlist(playlist_name);
	if (result == NULL)
	{
		throw ItemDoesNotExist();
	}
	delete current_place;
	current_place = new playlist_place(this , result);
}

void user::createPlaylist(string playlist_name) {
	playlist* exist = main_data->get_playlist(playlist_name);
	if (exist != NULL)
	{
		throw AlreadyExists();
	}
	playlist* result = new playlist(playlist_name,this);
	main_data->add_playlist(result);
	users_playlist.push_back(result);
}

void user::clearPlaylist(string playlist_name) {
	playlist* result = main_data->get_playlist(playlist_name);
	if (result == NULL)
	{
		throw ItemDoesNotExist();
	}
	result -> clearPlayList();
}

void user::remove(string music_name) {
	current_place->remove(music_name);
}

void user::orderItem (string music_name , int new_order) {
	current_place->orderItem(music_name,new_order);
}

void user::rate(int score) {
	current_place->rate(score);
}

string user::getArtist() {
	return current_place->getArtist();
}

string user::getAlbum() {
	return current_place->getAlbum();
}

int user::getLength() {
	return current_place->getLength();
}

string user::getName() {
	return current_place->getName();
}

string user::get_user_name() {
	return user_name;
}

string user::getCompleteName() {
	return current_place->getCompleteName();
}

int user::getRate() {
	return current_place->getRate();
}

int user::getUserRate() {
	return current_place->getUserRate();
}

int user::getCriticRate() {
	return current_place->getCriticRate();
}

void user::validate_item() {
	throw NotAuthorized();
}

void user::addMusic(string music_name, string music_file_path) {
	throw NotAuthorized();
}

void user::addAlbum(string artist_name, string album_name) {
	throw NotAuthorized();
}

void user::verifyUser(string username) {
	throw NotAuthorized();
}

UserData user::getUserDetails(string userName){
	user* selected_user = main_data->get_user(userName);
	if (selected_user == NULL)
	{
		throw MethodNotAvaliable();
	}
	UserData result;
	result.firstname = first_name;
	result.lastname=last_name;
	result.username=user_name;
	return result;
}

bool user::is_password_correct(string pass) {
	return pass == password;
}


void user::play() {
	vector<music*> result = current_place->play();
	for (int i = 0; i < result.size(); ++i)
	{
		users_queue->add_front(result[i]);
	}
	users_queue->play();
}

void user::next() {
	is_player();
	users_queue->next();
}

void user::previous() {
	is_player();
	users_queue->previous();
}

void user::pause() {
	is_player();
	users_queue->pause();
}

void user::shuffle() {
	is_player();
	users_queue->shuffle();
}

void user::repeat() {
	is_player();
	users_queue->repeat();
}

void user::repeatOne() {
	is_player();
	users_queue->repeatOne();
}












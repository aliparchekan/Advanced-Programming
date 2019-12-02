//
//  Database.cpp
//  
//
//  Created by Ali Parchekani on 12/30/17.
//

#include "Database.hpp"

using namespace std;

Database::Database() {
	current = NULL;
	UserData ali;
	ali.firstname = "";
	ali.lastname="";
	ali.username="admin";
	ali.userType = Admin;
	signup(ali,"admin");
}

music* Database::get_music(string music_name) {
	for (int i = 0; i < all_musics.size(); ++i)
	{
		if (all_musics[i]->getName() == music_name)
		{	
			return all_musics[i];
		}
	}
	return NULL;
}

album* Database::get_album(string album_name) {
	for (int i = 0; i < all_albums.size(); ++i)
	{
		if (all_albums[i]->getName() == album_name)
		{
			return all_albums[i];
		}
	}
	return NULL;
}

user* Database::get_user(string user_name) {
	for (int i = 0; i < all_users.size(); ++i)
	{
		if (all_users[i]->get_user_name() == user_name)
		{
			return all_users[i];
		}
	}
	return NULL;
}

artist* Database::get_artist(string user_name) {
	user* temp = get_user(user_name);
	artist* result = dynamic_cast<artist*> (temp);
	return result;
}

playlist* Database::get_playlist(string playlist_name) {
	for (int i = 0; i < all_playlists.size(); ++i)
	{
		if (all_playlists[i]->getName() == playlist_name)		
		{	
			return all_playlists[i];
		}
	}
	return NULL;
}

List Database::get_currents_playlists() {
	return current->get_user_playlists();
}

void Database::search_music(string name , List& result) {
	for (int i = 0; i < all_musics.size(); ++i)
	{
		if (all_musics[i]->getCompleteName().find(name) != std::string::npos)
		{
			//if (all_musics[i]->is_validated())
			//{
				result.push_back(all_musics[i]->getCompleteName());
			//}
		}
	}

}

List Database::search_all_music() {
	List result;
	for (int i = 0; i < all_musics.size(); ++i)
	{
		result.push_back(all_musics[i]->getCompleteName());
	}
	return result;
}

List Database::search_all_albums() {
	List result;
	for (int i = 0; i < all_albums.size(); ++i)
	{
		result.push_back(all_albums[i]->getCompleteName());
	}
	return result;
}

void Database::search_album(string name , List& result) {
	for (int i = 0; i < all_albums.size(); ++i)
	{
		if (all_albums[i]->getCompleteName().find(name) != std::string::npos)
		{
			if (all_albums[i]->is_validated())
			{
				result.push_back(all_albums[i]->getCompleteName());
			}
		}
	}
}

void Database::search_artist(string name , List& result) {
	for (int i = 0; i < all_users.size(); ++i)
	{
		if (all_users[i]->get_user_name().find(name) != std::string::npos)
		{
			if (all_users[i]->get_user_type() == Artist)
			{
				if (all_users[i]->is_verified())
				{
					result.push_back(all_users[i]->get_user_name());
				}
			}
		}
	}
}

void Database::search_playlist(string name , List& result) {
	for (int i = 0; i < all_playlists.size(); ++i)
	{
		if (all_playlists[i]->getCompleteName().find(name) != std::string::npos)
		{
			result.push_back(all_playlists[i]->getCompleteName());
		}
	}
}

void Database::add_music(music* temp) {
	all_musics.push_back(temp);
}

void Database::add_album(album* temp) {
	all_albums.push_back(temp);
}

void Database::add_playlist(playlist* temp) {
	all_playlists.push_back(temp);
}

void Database::enterBrowserMode() {
	current->enterBrowserMode();
}

void Database::goTohome() {
	current->goTohome();
}

void Database::goToPlaylists() {
	current->goToPlaylists();
}

void Database::goToLibrary() {
	current->goToLibrary();
}

void Database::goToArtist() {
	current-> goToArtist();
}


void Database::goToAlbum() {
	current->goToAlbum();
}

List Database::search (string target) {
	return current->search(target);
}

void Database::select(string target) {
	current->select(target);
}

List Database::list() {
	return current->list();
}

List Database::listMusics() {
	return current->listMusics();
}

List Database::listAlbums() {
	return current->listAlbums();
}

List Database::listPlaylists() {
	return current->listPlaylists();
}

List Database::listArtists() {
	return current->listArtists();
}

void Database::addTo(string target) {
	current->addTo(target);
}

void Database::goTo(string playlist_name) {
	current->goTo(playlist_name);
}

void Database::createPlaylist(string playlist_name) {
	current->createPlaylist(playlist_name);
}

void Database::clearPlaylist(string playlist_name) {
	current->clearPlaylist(playlist_name);
}

void Database::remove(string music_name) {
	current->remove(music_name);
}

void Database::orderItem (string music_name , int new_order) {
	current->orderItem(music_name,new_order);
}

void Database::rate(int score) {
	current->rate(score);
}

string Database::getArtist() {
	return current->getArtist();
}

string Database::getAlbum() {
	return current->getAlbum();
}

int Database::getLength() {
	return current->getLength();
}

string Database::getName() {
	return current->getName();
}

string Database::get_user_name() {
	return current->get_user_name();
}

string Database::getCompleteName() {
	return current->getCompleteName();
}

int Database::getRate() {
	return current->getRate();
}

int Database::getUserRate() {
	return current->getUserRate();
}

int Database::getCriticRate() {
	return current->getCriticRate();
}

void Database::validate() {
	current->validate_item();
}

void Database::addMusic(string music_name, string music_file_path) {
	current->addMusic(music_name,music_file_path);
}

void Database::addAlbum(string artist_name, string album_name) {
	current->addAlbum(artist_name,album_name);
}

void Database::verifyUser(string username) {
	current->verifyUser(username);
}

UserData Database::getUserDetails(string userName) {
	return current->getUserDetails(userName);
}

vector<music*> Database::get_musics() {
	return all_musics;
}

vector<album*> Database::get_albums() {
	return all_albums;
}

void Database::signup(UserData user_info , string password) {
	user* exist = get_user(user_info.username);
	if (exist != NULL )
	{
		throw AlreadyExists();
	}
	if (user_info.userType == Admin)
	{
		user* result = new admin(user_info.firstname,user_info.lastname,user_info.username,password,Admin,this);
		all_users.push_back(result);
		return;
	}
	if (user_info.userType == Artist)
	{
		user* result = new artist(user_info.firstname,user_info.lastname,user_info.username,password,Artist,this);
		cout << "successfully signed up" << endl;
		all_users.push_back(result);
		return;
	}
	if (user_info.userType == Editor)
	{
		user* result = new editor(user_info.firstname,user_info.lastname,user_info.username,password,Editor,this);
		cout << "successfully signed up" << endl;
		all_users.push_back(result);
		return;
	}
	user* result = new normal(user_info.firstname,user_info.lastname,user_info.username,password,Normal,this);
	all_users.push_back(result);
	cout << "successfully signed up" << endl;
	return;
}

void Database::login(string userName , string password) {
	user* result = get_user(userName);
	if (result->is_password_correct(password))
	{
		cout << "successfully logged in! " << endl;
		current = result;
		return;
	}
	throw InvalidCredentials();
}

void Database::play() {
	current->play();
}

void Database::enterPlayerMode() {
	current->enterPlayerMode();
}

void Database::next() {
	current->next();
}

void Database::previous() {
	current->previous();
}

void Database::pause() {
	current->pause();
}

void Database::shuffle() {
	current->shuffle();
}

void Database::repeat() {
	current->repeat();
}

List Database::search_all_artists() {
	List result;
	for (int i = 0; i < all_users.size(); ++i)
	{
		if (all_users[i]->get_user_type() == Artist)
		{
			result.push_back(all_users[i]->get_user_name());
		}
	}
	return result;
}







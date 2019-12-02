//
//  places.cpp
//  
//
//  Created by Ali Parchekani on 12/25/17.
//

#include "places.hpp"

using namespace std;


void places::goToPlaylists(){
	throw  MethodNotAvaliable();
}

void places::goToLibrary() {
	throw MethodNotAvaliable();
}

void places::goToArtist() {
	throw MethodNotAvaliable();
}

void places::goToAlbum() {
	throw MethodNotAvaliable();
}

List places::listMusics() {
	throw MethodNotAvaliable();
}

List places::listAlbums() {
	throw MethodNotAvaliable();
}

List places::listPlaylists() {
	throw MethodNotAvaliable();
}

List places::listArtists() {
	throw MethodNotAvaliable();
}

bool places::addTo(string target) {
	throw MethodNotAvaliable();
}

void places::rate(int score) {
	throw MethodNotAvaliable();
}

string places::getArtist() {
	throw MethodNotAvaliable();
}

string places::getAlbum() {
	throw MethodNotAvaliable();
}

int places::getLength() {
	throw MethodNotAvaliable();
}

int places::getRate() {
	throw MethodNotAvaliable();
}

int places::getUserRate() {
	throw MethodNotAvaliable();
}

int places::getCriticRate() {
	throw MethodNotAvaliable();
}

void places::validate_item() {
	throw MethodNotAvaliable();
}

string places::getName() {
	throw MethodNotAvaliable();
}

string places::getCompleteName() {
	throw MethodNotAvaliable();
}

List places::list() {
	throw MethodNotAvaliable();
}

bool places::is_not_listed(const List& result , string name) {
	for (int i = 0; i < result.size(); ++i)
	{
		if (result[i] == name)
		{
			return false;
		}
	}
	return true;
}

vector<music*> places::play() {
	vector<music*> result;
	return result;
}





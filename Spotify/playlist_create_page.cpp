#include "playlist_create_page.hpp"

using namespace std;

string playlist_create_page::parse_token(Request* req) {
	string result = req->getParam("token");
	if (result == "")
	{
		throw error();
	}
	return result;	
}

string playlist_create_page::parse_name(Request* req) {
	string result = req->getParam("name");
	if (result == "")
	{
		throw error();
	}
	return result;		
}

void playlist_create_page::callback(Request* req, Response* res) {
	string token,name;
	try {
		token = parse_token(req);
		name = parse_name(req);
	} catch (error e) {
		res->body << prepare_error_html();
		return;
	} 
	try {
		main_data -> createPlaylist(name);
	} catch (AlreadyExists e) {
		res -> body << prepare_repeat_error_html();
		return;
	}
	res->body << prepare_normal_html(name);
}

string playlist_create_page::prepare_normal_html( const string& name) {
	return "<html><style> body { background-image: radial-gradient(green, white);}</style><h1>GerdabServer</h1><p><font color=\"green\">Successfully created playlist " + name +" </font> </p> </html> ";
}

string playlist_create_page::prepare_error_html() {
	return "<html><style> body { background-image: radial-gradient(green, white);}</style><body><h1>GerdabServer</h1><p><font color=\"red\"> Insufficient info provided </font> </p></body></html> ";
}

string playlist_create_page::prepare_repeat_error_html() {
	return "<html><style> body { background-image: radial-gradient(green, white);}</style><body><h1>GerdabServer</h1><p><font color=\"red\"> User already exists </font> </p></body></html> ";
}
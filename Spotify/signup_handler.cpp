#include "signup_handler.hpp"

string signup_handler::parse_username(Request* req) {
	string result = req->getParam("username");
	cout << req->getParam("username") << endl;
	if (result == "")
	{
		throw error();
	}
	return result;
}

string signup_handler::parse_firstname(Request* req) {
	string result = req->getParam("firstname");
	if (result == "")
	{
		throw error();
	}
	return result;
}

string signup_handler::parse_lastname(Request* req) {
	string result = req->getParam("lastname");
	if (result == "")
	{
		throw error();
	}
	return result;
}

string signup_handler::parse_password(Request* req) {
	string result = req->getParam("password");
	if (result == "")
	{
		throw error();
	}
	return result;		
}

UserType signup_handler::parse_usertype(Request* req) {
	string result = req->getParam("usertype");
	if (result == "artist")
	{
			return Artist;
	}	
	if (result == "editor")
	{
		return Editor;
	}
	if (result == "admin")
	{
		return Admin;
	}
	if (result == "normal")
	{
		return Normal;
	}
	throw error();
}

void signup_handler::callback(Request* req, Response* res) {
	UserData temp;
	string password;
	try {
		temp.username = parse_username(req);
		temp.firstname = parse_firstname(req);
		temp.lastname = parse_lastname(req);
		temp.userType = parse_usertype(req);
		password = parse_password(req);
	} catch (error e) {
		res->body << prepare_error_html();
		return;
	}
	try {
		main_data -> signup(temp , password);
	} catch (AlreadyExists e) {
		res->body << prepare_repeat_error_html();
		return;
	}
	res->body << prepare_normal_html();
}

string signup_handler::prepare_normal_html() {
	return "<html><style> body { background-image: radial-gradient(green, white);}</style><h1>GerdabServer</h1><p><font color=\"green\">Successfully signed up </font> </p> </html> ";
}

string signup_handler::prepare_error_html() {
	return "<html><style> body { background-image: radial-gradient(green, white);}</style><body><h1>GerdabServer</h1><p><font color=\"red\"> Insufficient info provided </font> </p></body></html> ";
}

string signup_handler::prepare_repeat_error_html() {
	return "<html><style> body { background-image: radial-gradient(green, white);}</style><body><h1>GerdabServer</h1><p><font color=\"red\"> User already exists </font> </p></body></html> ";
}
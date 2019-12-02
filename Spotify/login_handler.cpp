#include "login_handler.hpp"

using namespace std;

string login_handler::parse_username(Request* req) {
	string result = req->getParam("username");
	cout << req->getParam("username") << endl;
	if (result == "")
	{
		throw error();
	}
	return result;
}

string login_handler::parse_password(Request* req) {
	string result = req->getParam("password");
	if (result == "")
	{
		throw error();
	}
	return result;		
}

void login_handler::callback(Request* req, Response* res) {
	string username,password;
	try {
		username = parse_username(req);
		password = parse_password(req);
	} catch (error e) {
		res->body << prepare_error_html();
		return;
	}
	try {
		main_data -> login(username,password);
	} catch(InvalidCredentials e) {
		res->body << prepare_wrong_password_html();
		return;
	}
	res->body << prepare_normal_html();
}

string login_handler::prepare_normal_html() {
	return "<html><style> body { background-image: radial-gradient(green, white);}</style><body><h1>GerdabServer</h1><p><font color=\"green\">Successfully logged in </font> </p></body></html> ";
}

string login_handler::prepare_error_html() {
	return "<html><style> body { background-image: radial-gradient(green, white);}</style><body><h1>GerdabServer</h1><p><font color=\"red\"> Insufficient info provided </font> </p></body></html> ";
}

string login_handler::prepare_wrong_password_html() {
	return "<html><style> body { background-image: radial-gradient(green, white);}</style><body><h1>GerdabServer</h1><p><font color=\"red\"> Wrong username/password </font> </p></body></html> ";
}
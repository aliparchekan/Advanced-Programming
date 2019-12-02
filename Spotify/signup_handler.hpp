#ifndef signup_handler_hpp
#define signup_handler_hpp

#include <iostream>
#include <string>
#include "gerdabServer.hpp"
#include "api.hpp"
#include "Database.hpp"
#include "exceptions.hpp"

class Database;

class signup_handler : public RequestHandler
{
public:
	signup_handler(Database* a) : main_data(a) {}
	string prepare_normal_html();
	string prepare_error_html();
	string prepare_repeat_error_html();
	UserType parse_usertype(Request* req);
	void callback(Request* req, Response* res);
	string parse_username(Request* req);
	string parse_firstname(Request* req);
	string parse_lastname(Request* req);
	string parse_password(Request* req);
private:
	Database* main_data;
};




#endif
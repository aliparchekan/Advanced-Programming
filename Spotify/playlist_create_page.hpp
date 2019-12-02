#ifndef playlist_create_page_hpp
#define playlist_create_page_hpp

#include <iostream>
#include <string>
#include "gerdabServer.hpp"
#include "Database.hpp"
#include "api.hpp"
#include "exceptions.hpp"

class playlist_create_page : public RequestHandler
{
public:
	playlist_create_page(Database* a) : main_data(a) {}
	string parse_token(Request* req);
	string parse_name(Request* req);
	string prepare_normal_html(const string& name);
	void callback(Request* req, Response* res);
	string prepare_error_html();
	string prepare_repeat_error_html();


private:
	Database* main_data;
	
};


#endif
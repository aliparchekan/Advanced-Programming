#ifndef artist_page_handler_hpp
#define artist_page_handler_hpp

#include <iostream>
#include <string>
#include "gerdabServer.hpp"
#include "Database.hpp"
#include "api.hpp"
#include "exceptions.hpp"

class artist_page_handler : public RequestHandler
{
public:
	artist_page_handler(Database* a) : main_data(a) {}
	string prepare_normal_html(const List& result  );
	string prepare_error_html();
	string parse_token(Request* req);
	void callback(Request* req, Response* res);
	void parse_list(string& a , string& b , string& c , const string& result);

private:
	Database* main_data;
};


#endif
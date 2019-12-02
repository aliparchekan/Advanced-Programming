#ifndef playlist_page_handler_hpp
#define playlist_page_handler_hpp

#include <iostream>
#include <string>
#include "gerdabServer.hpp"
#include "Database.hpp"
#include "api.hpp"
#include "exceptions.hpp"

class playlist_page_handler : public RequestHandler
{
public:
	playlist_page_handler(Database* a) : main_data(a) {}
	string prepare_normal_html(const List& result  );
	string prepare_error_html();
	string parse_token(Request* req);
	void callback(Request* req, Response* res);



private:
	Database* main_data;
	
};


#endif
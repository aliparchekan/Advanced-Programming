#ifndef search_handler_hpp
#define search_handler_hpp

#include "api.hpp"
#include "Database.hpp"
#include "gerdabServer.hpp"
#include "exceptions.hpp"
#include <string>


class search_handler : public RequestHandler
{
public:
	search_handler(Database* a) : main_data(a) {}
	string parse_token(Request* req);
	string parse_keyword(Request* req);
	void callback(Request* req , Response* res);
	string prepare_html(const List& result);
	void parse_list(string& a , string& b , string& c , const string& result);
	string prepare_error_html();
private:
	Database* main_data;
	
};











#endif
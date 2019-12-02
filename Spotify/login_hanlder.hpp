#ifndef login_handler_hpp
#define login_handler_hpp

#include "gerdabServer.hpp"
#include "Database.hpp"
#include "exceptions.hpp"

class login_handler : public RequestHandler
{
public:
	login_hanlder(Database* a) : main_data(a) {}
	string prepare_normal_html();
	string prepare_error_html();
	string prepare_wrong_password_html();
	string parse_username(Request* req);
	string parse_password(Request* req);
	void callback(Request* req, Response* res);

private:
	Database* main_data;
	
};





#endif
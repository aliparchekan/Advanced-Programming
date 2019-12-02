#ifndef home_page_handler_hpp
#define home_page_handler_hpp

#include <iostream>
#include <string>
#include "gerdabServer.hpp"

class RequestHandler;

class home_page_handler : public RequestHandler
{
public:
	home_page_handler();
	void callback(Request* req, Response* res);
	string prepare_html();
	
};
















#endif
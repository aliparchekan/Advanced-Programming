#include "home_page_handler.hpp"


home_page_handler::home_page_handler() {
}

string home_page_handler::prepare_html() {
	return "<html><style> body { background-image: radial-gradient(green, white);}</style><body><h1>GerdabServer</h1><p><font color=\"blue\">Welcome to Gerdabify Server </font> </p></body></html>";
}

void home_page_handler::callback(Request* req, Response* res) {
	cout<<req->getParam("token")<<endl;
        res->body << prepare_html();
}
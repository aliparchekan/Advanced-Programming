#include "search_handler.hpp"

using namespace std;

string search_handler::parse_token(Request* req) {
	string result = req->getParam("token");
	if (result == "")
	{
		throw error();
	}
	return result;	
}

string search_handler::parse_keyword(Request* req) {
	string result = req->getParam("keyword");
	if (result == "")
	{
		throw error();
	}
	return result;

}

void search_handler::parse_list(string& a , string& b , string& c , const string& result) {
	size_t first,second;
	first = result.find('-');
	second = result.find('-',first + 1);
	a = result.substr(0,first);
	b = result.substr(first + 1,second - first - 1);
	c = result.substr(second + 1);

}

string search_handler::prepare_html(const List& result) {
	if (result.size() == 0)
	{
		return "<html><style> body { background-image: radial-gradient(green, white);}</style><body><h1>GerdabServer</h1><p><font color=\"red\">Your search didn't have any result </font> </p></body></html>";
	}
	string output = "<html><style> body { background-image: radial-gradient(green, white);}</style><body><h1>GerdabServer</h1><p><font color=\"green\">Found results: </font> </p><style> table{ width:100%; } table, td{ border:1px solid rgb(70, 50, 110); color:rgb(70, 50, 110); } td{ padding:5px; border-spacing:20px;} table tr:nth-child(even){ background-color: rgba(100, 140, 110, 0.2);} table tr:nth-child(odd){background-color: rgb(255, 255, 255); }</style><table> <th> Artist name </th> <th> Album name </th> <th> Song name </th>";
	for (int i = 0; i < result.size(); ++i)
	{
		string a,b,c;
		parse_list(a,b,c,result[i]);
		output = output + "<tr><td>" + a + "</td><td>" + b + "</td><td>" + c + "</td></tr>";
	}
	output = output + "</table></body></html>";
	return output;
}

string search_handler::prepare_error_html() {
	return "<html><style> body { background-image: radial-gradient(green, white);}</style><body><h1>GerdabServer</h1><p><font color=\"red\"> Insufficient info provided </font> </p></body></html> ";
}


void search_handler::callback(Request* req , Response* res) {
	string token,keyword;
	try{
		token = parse_token(req);
		keyword = parse_keyword(req);
	} catch (error e) {
		res->body << prepare_error_html();
		return;
	} 
	List result;
	main_data->search_music(keyword,result);
	res->body << prepare_html(result);
}
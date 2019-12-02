#include "playlist_page_handler.hpp" 


using namespace std;

string playlist_page_handler::parse_token(Request* req){
	string result = req->getParam("token");
	if (result == "")
	{
		throw error();
	}
	return result;	
}

string playlist_page_handler::prepare_error_html() {
	return "<html><style> body { background-image: radial-gradient(green, white);}</style><body><h1>GerdabServer</h1><p><font color=\"red\"> Insufficient info provided </font> </p></body></html> ";
}

string playlist_page_handler::prepare_normal_html(const List& result) {
	if (result.size() == 0)
	{
		return "<html><style> body { background-image: radial-gradient(green, white);}</style><body><h1>GerdabServer</h1><p><font color=\"red\">Your search didn't have any result </font> </p></body></html>";
	}
	string output = "<html><style> body { background-image: radial-gradient(green, white);}</style><body><h1>GerdabServer</h1><p><font color=\"green\">Found results: </font> </p><style> table{ width:100%; } table, td{ border:1px solid rgb(70, 50, 110); color:rgb(70, 50, 110); } td{ padding:5px; border-spacing:20px;} table tr:nth-child(even){ background-color: rgba(100, 140, 110, 0.2);} table tr:nth-child(odd){background-color: rgb(255, 255, 255); }</style><table> <th> Playlist name </th> ";
	for (int i = 0; i < result.size(); ++i)
	{
		output = output + "<tr><td>" + result[i] + "</td></tr>";
	}
	output = output + "</table></body></html>";
	return output;
}

void playlist_page_handler::callback(Request* req, Response* res) {
	string token;
	try{
		token = parse_token(req);
	} catch (error e) {
		res->body << prepare_error_html();
		return;
	} 
	List result;
	result = main_data->get_currents_playlists();
	res->body << prepare_normal_html(result);
}
//
//  main.cpp
//  
//
//  Created by Ali Parchekani on 12/30/17.
//

#include "main.hpp"


int main() {
	// Database a;
	// UserData ali;
	// ali.firstname = "ali";
	// ali.lastname="Parchekani";
	// ali.username="aliparche";
	// ali.userType = Artist;

	
	// a.signup(ali,"1234");
	// a.login("admin","admin");
	// a.verifyUser("aliparche");
	// a.login("aliparche","1234");
	// a.enterBrowserMode();
	// a.goTohome();
	// cout << "hello" << endl;
	// a.addMusic("aa","../Desktop/Gerdab-master/examples/beat.wav");
	// a.addAlbum("aliparche" , "bad");
	// cout << "album created" << endl;
	// a.goToLibrary();
	// List result = a.listAlbums();
	// for (int i = 0; i < result.size(); ++i)
	// {
	// 	cout << result[i] << endl;
	// }
	// a.createPlaylist("sharm");
	// a.select("aa");
	// a.addTo("sharm");
	// a.addTo("queue");
	// a.addTo("bad");
	// a.goTo("sharm");
	// result = a.list();
	// cout << a.getCompleteName() << endl;
	// for (int i = 0; i < result.size(); ++i)
	// {
	// 	cout << result[i] << endl;
	// }
	// a.select("aa");
	// cout << "aa artist is :" << a.getArtist() << endl;
	// a.goTohome();
	// cout << "in home" << endl;
	// a.goToLibrary();
	// cout << "in library" << endl;
	// result = a.listArtists();
	// //cout << a.getCompleteName() << endl;
	// for (int i = 0; i < result.size(); ++i)
	// {
	// 	cout << result[i] << endl;
	// }
	// cout  << "hi" << endl;
	// a.play();
	// cout << "bye" << endl;
	// a.play();
	// a.play();
	// a.play();
	// a.goTohome();
	// a.goToPlaylists();
	// result = a.list();
	// for (int i = 0; i < result.size(); ++i)
	// {
	// 	cout << result[i] << endl;
	// }
	// //a.login("admin","admin");

	 try {
	 	Database a;
        Server server;
        UserData ali;
		ali.firstname = "ali";
		ali.lastname="Parchekani";
		ali.username="aliparche";
		ali.userType = Artist;

	
		a.signup(ali,"1234");
		a.login("admin","admin");
		a.verifyUser("aliparche");
		a.login("aliparche","1234");
		a.enterBrowserMode();
		a.goTohome();
		a.addMusic("aa","../Desktop/Gerdab-master/examples/beat.wav");
		a.addAlbum("aliparche" , "bad");
		a.select("aa");
		a.addTo("bad");
		a.select("aa");
		a.createPlaylist("sharm");
		//a.validate();
        RequestHandler* homePage = new home_page_handler();
        RequestHandler* signuppage = new signup_handler(&a);
        RequestHandler* loginpage = new login_handler(&a);
        RequestHandler* searchpage = new search_handler(&a);
        RequestHandler* musicpage = new music_page_handler(&a);
        RequestHandler* albumpage = new album_page_handler(&a);
        RequestHandler* artistpage = new artist_page_handler(&a);
        RequestHandler* playlistpage = new playlist_page_handler(&a);
        RequestHandler* playlistcreate = new playlist_create_page(&a);
       // RequestHandler* form = new FormHandler();
        server.get("/home", homePage);
        server.post("/signup" , signuppage);
        server.post("/login" , loginpage);
        server.post("/search",searchpage);
        server.get("/musics",musicpage);
        server.get("/albums",albumpage);
        server.get("/artists",artistpage);
        server.get("/playlists",playlistpage);
        server.post("/playlists",playlistcreate);
       // server.post("/form", form);
        cout << "Listening on port 5000" << endl;
        server.start(5000);
    } catch(Exception e) {
        cerr << "WebServer: " << e.getMessage() << endl;
    }

    return EXIT_SUCCESS;
}
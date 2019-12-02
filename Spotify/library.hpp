//
//  library.hpp
//  
//
//  Created by Ali Parchekani on 12/28/17.
//

#ifndef library_hpp
#define library_hpp

#include <iostream>
#include "places.hpp"
#include "Database.hpp"

#include "music.hpp"


class music;
class user;
class places;
class Database;

class library: public places {
public:
	library(Database* a , user* b) : places(b) {main_data = a;}
	List list();
	
	List listMusics();
	List listAlbums();
	List listArtists();
private:
	Database* main_data;
};

#include "user.hpp"

#endif /* library_hpp */

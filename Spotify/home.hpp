//
//  home.hpp
//  
//
//  Created by Ali Parchekani on 12/28/17.
//

#ifndef home_hpp
#define home_hpp

#include <iostream>
#include <vector>
#include "places.hpp"
#include "api.hpp"


class places;
class user;


class home : public places
{
public:
	home(user* a) : places(a) {}
	void goToPlaylists() {}
	void goToLibrary() {}
	List list();	
};

#include "user.hpp"

#endif /* home_hpp */

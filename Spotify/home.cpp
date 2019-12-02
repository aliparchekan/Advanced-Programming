//
//  home.cpp
//  
//
//  Created by Ali Parchekani on 12/28/17.
//

#include "home.hpp"

using namespace std;

List home::list() {
	List result;
	result.push_back("playlists");
	result.push_back("library");
	return result;
}

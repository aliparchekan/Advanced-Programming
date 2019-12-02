//
//  admin.cpp
//  
//
//  Created by Ali Parchekani on 12/30/17.
//

#include "admin.hpp"

using namespace std;

void admin::validate_item() {
	current_place->validate_item();
}

void admin::verifyUser(string username) {
	user* result=main_data->get_user(username);
	if (result == NULL)
	{
		throw ItemDoesNotExist();
	}
	result -> get_verified();
}
//
//  editor.hpp
//  
//
//  Created by Ali Parchekani on 12/30/17.
//

#ifndef editor_hpp
#define editor_hpp

#include <iostream>
#include "user.hpp"
#include "api.hpp"
#include "Database.hpp"

class user;
class Database;

class editor :public user
{
public:
	editor(string fname , string lname , string uname , string password ,UserType Editor ,Database* a ) : user(fname,lname,uname,password,Editor , a) {}
	virtual UserType get_user_type() {return Editor;}
};


#endif /* editor_hpp */

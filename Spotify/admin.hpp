//
//  admin.hpp
//  
//
//  Created by Ali Parchekani on 12/30/17.
//

#ifndef admin_hpp
#define admin_hpp

#include <iostream>
#include "user.hpp"
#include "api.hpp"
#include "Database.hpp"

class user;
class Database;

class admin :public user
{
public:
	admin(string fname , string lname , string uname , string password ,UserType Normal ,Database* a ) : user(fname,lname,uname,password,Normal , a) {}
	void validate_item();
	void verifyUser(string username);
	virtual UserType get_user_type() {return Admin;}
};


#endif /* admin_hpp */

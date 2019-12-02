//
//  normal.hpp
//  
//
//  Created by Ali Parchekani on 12/30/17.
//

#ifndef normal_hpp
#define normal_hpp

#include <iostream>
#include "user.hpp"
#include "api.hpp"
#include "Database.hpp"

class user;
class Database;

class normal :public user
{
public:
	normal(string fname , string lname , string uname , string password ,UserType Normal ,Database* a ) : user(fname,lname,uname,password,Normal , a) {}
	virtual UserType get_user_type() {return Normal;}
};

#endif /* normal_hpp */

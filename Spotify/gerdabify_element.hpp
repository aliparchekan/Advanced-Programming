
//
//  gerdabify_element.hpp
//  
//
//  Created by Ali Parchekani on 12/23/17.
//

#ifndef gerdabify_element_hpp
#define gerdabify_element_hpp

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

#define NOT_FOUND -1

class user;

class gerdabify_element {
public:
	gerdabify_element(string _name);
    virtual string getArtist() = 0;
    virtual string getAlbum() = 0;
    virtual int getLength() = 0;
    string getName();
    virtual string getCompleteName() = 0;
    virtual int getRate(string user_name);
    virtual int getUserRate();
    virtual int getCriticRate();
    int get_user_index(string user_name);
    virtual void rate(user* new_user , int rate);
    void validate();
    bool is_validated() {return validated;}
private:
	string name;
	vector<user*> users_given_rate;
	vector<int> rates;
	bool validated;
};

#include "user.hpp"
//#include "api.hpp"


#endif /* gerdabify_element_hpp */

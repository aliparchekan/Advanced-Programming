//
//  gerdabify_element.cpp
//  
//
//  Created by Ali Parchekani on 12/23/17.
//

#include "gerdabify_element.hpp"

using namespace std;

gerdabify_element::gerdabify_element(string _name) {
	name = _name;
	validated = false;
}

string gerdabify_element::getName() {
	return name;
}

int gerdabify_element::get_user_index(string user_name) {
	for (int i = 0; i < users_given_rate.size(); ++i)
	{
		if (users_given_rate[i]->get_user_name() == user_name)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

int gerdabify_element::getRate(string user_name) {
	int index = get_user_index(user_name);
	if (index == NOT_FOUND)
	{
		// CHI BAYAD BASHE?
		abort();
	}
	return rates[index];
}

int gerdabify_element::getUserRate() {
	int result = 0;
	for (int i = 0; i < rates.size(); ++i)
	{
		result += rates[i];
	}
	return (result/rates.size());
}

int gerdabify_element::getCriticRate() {
	int result = 0;
	int count = 0;
	for (int i = 0; i < users_given_rate.size(); ++i)
	{
		if (users_given_rate[i]->get_user_type() == Editor)
		{
			count++;
			result += rates[i];
		}
	}
	return result/count;
}

void gerdabify_element::rate(user* new_user , int rate) {
	users_given_rate.push_back(new_user);
	rates.push_back(rate);
}

void gerdabify_element::validate() {
	validated = true;
}







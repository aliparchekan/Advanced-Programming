//
//  queue_place.hpp
//  
//
//  Created by Ali Parchekani on 12/30/17.
//

#ifndef queue_place_hpp
#define queue_place_hpp

#include <iostream>
#include "places.hpp"
#include "queue.hpp"

class places;
class queue;

class queue_place : public places
{
public:
	queue_place(user* a , queue* b) : places(a) , current(b) {}
	List list();
	List listMusics();
	List listAlbums();
	void remove(string music_name);
	void orderItem (string music_name , int new_order);
	string getName() {return "";}
	string getCompleteName() {return "";}
	vector<music*> play();
private:
	queue* current;
	
};

#endif /* queue_place_hpp */

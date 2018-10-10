/*
 * Event.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "Event.h"

Event::Event(int time) {
	nextEvent=nullptr;
	this->time = time;
}
int Event::getEventTime(){
	return time;
}
Event::~Event() {
	// TODO Auto-generated destructor stub
}


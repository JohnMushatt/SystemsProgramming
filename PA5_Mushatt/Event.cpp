/*
 * Event.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "Event.h"

Event::Event() {
	nextEvent=nullptr;
	time = -1;
}
float Event::getTime() {
	return time;
}
void Event::action(float currentTime, TellerQueue** queues, int numTellers,
		EventQueue *simulationQueue) {

}
void Event::setNext(Event *event) {
	nextEvent=event;
}
Event *Event::getNextEvent() {
	return nextEvent;
}
Event::~Event() {
	// TODO Auto-generated destructor stub
}


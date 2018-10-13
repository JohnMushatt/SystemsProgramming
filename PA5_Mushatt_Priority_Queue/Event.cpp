/*
 * Event.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "Event.h"
/**
 * Constructor for event
 */
Event::Event() {
	nextEvent=nullptr;
	time = -1;
}
/**
 * Retrieve time for the event
 * @return time of the event
 */
float Event::getTime() {
	return time;
}
/**
 * Action for the event, to be overriden by subclasses
 * @param currentTime Current sim time
 * @param queues Teller queues
 * @param numTellers # of tellers
 * @param simulationQueue Event Queue
 */
void Event::action(float currentTime, TellerQueue** queues, int numTellers,
		EventQueue *simulationQueue) {

}
/**
 * Set the next event for the current event
 * @param event Pointer to event to update to
 */
void Event::setNext(Event *event) {
	nextEvent=event;
}
/**
 * Retrieve the next event
 * @return The next event
 */
Event *Event::getNextEvent() {
	return nextEvent;
}
Event::~Event() {
	// TODO Auto-generated destructor stub
}


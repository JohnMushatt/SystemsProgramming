/*
 * CustomerEvent.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "CustomerEvent.h"
#include "EventQueue.h"
#include "Customer.h"
#include "TellerQueue.h"
#include <iostream>
/**
 * Constructor
 * @param beginningTime Start time for the event
 */
CustomerEvent::CustomerEvent(float beginningTime) {
	//Beginnign time
	startTime = beginningTime;
	//Set end time to a default
	endTime = 0;
	//Set current time to beginning time
	time = beginningTime;
	//Set whether or not this event has been processed by a teller
	receivingService=false;

}
/**
 * Retreieve event time
 * @return event time
 */
float CustomerEvent::getTime() {
	return this->time;
}

/**
 * Set whether this event has been processed by a teller
 */
void CustomerEvent::setService() {
	receivingService=true;
}
/**
 * Retrieve service status
 * @return True if processed, false if unprocessed
 */
bool CustomerEvent::getServicing() {
	return receivingService;
}
/**
 * Retrieve start Time
 * @return start time for event
 */
int CustomerEvent::getStartTime() {
	return startTime;
}
/**
 * Retrieve end time
 * @return end time for the event
 */
int CustomerEvent::getEndTime() {
	return endTime;
}
/**
 * Update the events current time
 * @param currentTime Time to update to
 */
void CustomerEvent::setTime(float currentTime) {
	time = currentTime;
}
/**
 * Retrieve the shortest line amongt a 2d array of tellerqueues
 * @param lines Pointer to teller queues
 * @param numLines # of teller queues
 * @return The shortest line
 */
TellerQueue* CustomerEvent::findShortestLine(TellerQueue** lines, int numLines) {

	//Get the 0th tellerqueue
	TellerQueue* shortestLine = lines[0];
	//Get 0th's size
	int shortestLineSize = shortestLine->getQueueSize();
	//Compare against the rest
	for (int i = 1; i < numLines; i++) {
		//Get next tellerqueue
		TellerQueue* line = lines[i];
		//If it is smaller, switch
		if (line->getQueueSize() < shortestLineSize) {
			shortestLine = line;
			shortestLineSize = line->getQueueSize();
		}
	}
	//Return the shortest line
	return shortestLine;
}
/**
 * The action to be called on by the Event Queue
 * @param currentTime time to update endTime
 * @param queues Teller queues to check/use
 * @param numTellers # of teller queues
 * @param simulationQueue Event Queue to update for action
 */
void CustomerEvent::action(float currentTime, TellerQueue** queues,
		int numTellers, EventQueue *simulationQueue) {

	//Process the current head of the event queue
	simulationQueue->removeEvent();
	//If the customer has been process, update the end time for stats
	if (receivingService) {
		endTime = currentTime;
	}
	//Else retrieve the smallest queue and add a new customer to that queue
	else {
		//Smallest queue currently
		TellerQueue *q = findShortestLine(queues,numTellers);
		//New customer to add
		Customer *customer = new Customer(this);
		//Add customer to the queue
		q->addCustomer(customer);
	}

}
CustomerEvent::~CustomerEvent() {
	// TODO Auto-generated destructor stub
}


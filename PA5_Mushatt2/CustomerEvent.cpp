/*
 * CustomerEvent.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: tjferrara
 */

#include "CustomerEvent.h"
#include "TellerQueue.h"
#include "TellerQueueNode.h"
#include "EventQueue.h"
#include <stdio.h>

/** Constructs CustomerEvent and initializes private variables
 * @param aTime arrival time to be used for class
 */
CustomerEvent::CustomerEvent(float aTime) {
	time = aTime;
	leaveTime = -1;
	arrivalTime = aTime;
	servicing = false;
}

/** Destructs CustomerEvent
 */
CustomerEvent::~CustomerEvent() {
	// TODO Auto-generated constructor stub

}

/**Handles CustomerEvent arrival and departure from 'Bank'
 * @param clock running clock of simulation
 * @param lines array of TellerQueues
 * @param numLines number of TellerQueues in lines array
 * @param eventQueue Queue being used as time-line
 */
void CustomerEvent::action(float clock, TellerQueue** lines, int numLines, EventQueue* eventQueue) {

	eventQueue->pop(); // removing this element from queue

	if (servicing) { // Was customer being serviced???
		// set departure time
		leaveTime = clock;
	} else {		// Find a line to be serviced
		// Find Shortest Line
		TellerQueue* line = findShortestLine(lines, numLines);
		// Add Customer to that line
		TellerQueueNode* newCustomerNode = new TellerQueueNode(this);
		line->push(newCustomerNode);
	}
}

/**Finds TellerQueue with the shortest length
 * @param lines array of TellerQueues
 * @param numLines number of TellerQueues in lines array
 * @return TellerQueue with the shortest line
 */
TellerQueue* CustomerEvent::findShortestLine(TellerQueue** lines, int numLines) {
	TellerQueue* shortestLine = lines[0];
	int shortestLineSize = shortestLine->getSize();
	// i starts at 1 because we are using shortestLine as 0 index
	for (int i = 1; i < numLines; i++) {
		TellerQueue* line = lines[i];
		if (line->getSize() < shortestLineSize) {
			shortestLine = line;
			shortestLineSize = line->getSize();
		}
	}
	return shortestLine;
}

/**Sets Priority time for CustomerEvent
 * @param t time value
 */
void CustomerEvent::setTime(float t) {
	time = t;
}

/**Gets Priority Time value
 * @return priority time value
 */
float CustomerEvent::getTime() {
	return time;
}

/**Gets Leave Time value
 * @return leave time value
 */
float CustomerEvent::getLeaveTime() {
	return leaveTime;
}

/**Gets Arrival Time value
 * @return arrival time value
 */
float CustomerEvent::getArrivalTime() {
	return arrivalTime;
}

/**Sets servicing value to true
 */
void CustomerEvent::setServicing() {
	servicing = true;
}

/**Gets servicing boolean value
 * @param servicing value
 */
bool CustomerEvent::getServicing() {
	return servicing;
}

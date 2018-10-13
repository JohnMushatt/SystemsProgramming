/*
 * TellerEvent.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: tjferrara
 */

#include "TellerEvent.h"
#include "EventQueue.h"
#include <stdio.h>

/**Constructs TellerEvent
 */
TellerEvent::TellerEvent(float sTime, float iTime, TellerQueue* line) {
	queue = line;
	// set to zero to start, because
	// tellers are the FIRST ones to
	// arrive at the bank
	time = 0;
	serviceTime = sTime;
	idleTime = iTime;
	numServices = 0;
	numIdles = 0;
}

/**Destructs TellerEvent
 */
TellerEvent::~TellerEvent() {

}

/**Handles TellerEvent arrival, manages Customers in line, and
 * decides when to go on break (idle time)
 * @param clock running clock of simulation
 * @param lines array of TellerQueues
 * @param numLines number of TellerQueues in lines array
 * @param eventQueue Queue being used as time-line
 */
void TellerEvent::action(float clock, TellerQueue** lines, int numLines, EventQueue* eventQueue) {

	eventQueue->pop(); // removing this element from queue

	// Look for Customers in Line
	if (queue->getSize() > 0) {
		// Get that customer
		CustomerEvent* customer = queue->top()->getVal();
		// Set new Priority time
		customer->setTime(clock + serviceTime);
		// Customer is being service
		customer->setServicing();
		// Remove them from Teller Queue
		queue->pop();
		// Change new time indicator for priority
		time = clock + serviceTime;
		// Add to number of services
		numServices++;
		// Place Teller back in Queue for serviceTime
		eventQueue->push(this);
		// Place Customer back in Queue
		eventQueue->push(customer);
	} else {	// No customers in line
		// Steal customer from another line
		CustomerEvent* customer = getCustomerFromLargestLine(lines, numLines);
		if (customer == NULL) { // No more customers to help and goes on break
			// Set random (SMALL) break time

			time += idleTime; /////////// HOW BIG IS IDLE TAKEING UP>>>?????????????????

			// Add to Number of Idle Times
			numIdles++;
			// Place Teller back in Queue for idolTime
			eventQueue->push(this);
		} else {				// Help that Customer
			// Set new Priority time
			customer->setTime(clock+serviceTime);
			// Customer is being service
			customer->setServicing();
			// Change new time indicator for priority
			time = clock + serviceTime;
			// Add to number of services
			numServices++;
			// Place Teller back in Queue for serviceTime
			eventQueue->push(this);
			// Place Customer back in Queue
			eventQueue->push(customer);
		}
	}
}

/**Gets Customer the first customer from the largest TellerQueue
 * @param lines array of TellerQueues
 * @param numLines number of TellerQueus in array
 * @return First CustomerEvent from largest line
 */
CustomerEvent* TellerEvent::getCustomerFromLargestLine(TellerQueue** lines, int numLines) {
	TellerQueue* largestLine = NULL;
	int largestLineLength = 0;
	for (int i = 0; i < numLines; i++) {
		TellerQueue* line = lines[i];
		if (line != queue) { // skip over own line
			if (line->getSize() > largestLineLength) { // found larger line
				largestLine = line;
				largestLineLength = line->getSize();
			}
		}
	}
	if (largestLine == NULL) { // no largest line
		return NULL;
	} else {
		CustomerEvent* customer = largestLine->top()->getVal();
		largestLine->pop();
		return customer;
	}

}

/**Gets Service Time for TellerEvent
 * @return service time value
 */
float TellerEvent::getServiceTime() {
	return serviceTime;
}

/**Gets Priority Time value
 * @return priority time value
 */
float TellerEvent::getTime() {
	return time;
}

/**Sets Priority time for TellerEvent
 * @param t time value
 */
void TellerEvent::setTime(float t) {
	time = t;
}

/**Gets Number of times Teller serviced a Customer
 * @return number of services
 */
int TellerEvent::getNumServices() {
	return numServices;
}

/**Gets Idle Time for TellerEvent
 * @return idle time
 */
float TellerEvent::getIdleTime() {
	return idleTime;
}

/**Gets Number of times Teller took an idle break
 * @return number of idle times
 */
int TellerEvent::getNumIdles() {
	return numIdles;
}


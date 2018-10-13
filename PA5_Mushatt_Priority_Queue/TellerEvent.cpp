/*
 * TellerEvent.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "TellerEvent.h"
#include "EventQueue.h"
#include <iostream>
/**
 * Constructor
 * @param tellerServiceTime time it takes for a teller to service a customer
 * @param idletTime time it takes for a teller to complete 1 idle
 */
TellerEvent::TellerEvent(float tellerServiceTime, float idleTime,
		TellerQueue *queue) {
	this->tellerServiceTime = tellerServiceTime;
	this->idleTime = idleTime;
	totalServices = 0;
	time = 0;
	this->queue = queue;
	totalIdles = 0;
	totalServices = 0;
	totalIdles = 0;
}
/**
 * Retrieve  event's time
 * @return event's time
 */
float TellerEvent::getTime() {
	return time;
}
/**
 * Retrieve the total idles of the event
 * @return # of idle times
 */
int TellerEvent::getTotalIdles() {
	return totalIdles;
}
/**
 * Retrieve total services
 * @return # of services
 */
int TellerEvent::getTotalServices() {
	return totalServices;
}
/**
 * Retrieve idle time for the teller
 * @return idle time
 */
float TellerEvent::getIdleTime() {
	return idleTime;
}
/**
 * Retrieve how long a teller services someone
 * @return time it takes to service
 */
float TellerEvent::getServiceTime() {
	return tellerServiceTime;
}
/**
 * Action event for tellerevent
 * @param currentTime time of the simulation
 * @param queues Teller queues array
 * @param numTellers # of tellers
 * @simulationQueue Event queue
 */
void TellerEvent::action(float currentTime, TellerQueue** queues,
		int numTellers, EventQueue *simulationQueue) {

	//Process event queue head
	simulationQueue->removeEvent();
	//If there are customers in the queue
	if (queue->getQueueSize() > 0) {

		//Create a new customer to add to the queue
		CustomerEvent *cust = queue->getHead()->getCustomerEvent();
		//Update its time to be correct
		cust->setTime(currentTime + this->getServiceTime());
		//Set it to having been serviced
		cust->setService();
		//std::cout<<"Customer has received service!\n";
		//Remove it from the queue as it has been processed
		queue->removeCustomer();
		//Update internal time
		time = currentTime + tellerServiceTime;
		//Update service stat
		totalServices++;
		//Add customer and teller event for the eventqueue
		simulationQueue->addEvent(this);
		simulationQueue->addEvent(cust);
	}
	//There are no customers currently
	else {
		//Try to grab a customer from another queue
		CustomerEvent *cust = checkOtherQueues(queues, numTellers);
		//If there are no more customers
		if (cust == nullptr) {
			//Update to be on idle
			time += this->idleTime;
			totalIdles++;
			//Send idle event to EventQueue
			simulationQueue->addEvent(this);

		}
		//There is a custoemr we can service
		else {
			//Update that customer's time
			cust->setTime(currentTime + tellerServiceTime);
			//Service them
			cust->setService();
			//std::cout<<"Customer has received service!\n";
			time = currentTime + tellerServiceTime;
			totalServices++;

			//Send events to update event queue
			simulationQueue->addEvent(this);
			simulationQueue->addEvent(cust);
		};
	}
}
/**
 * Check other queues if the current queue is empty
 * @param queues Teller queues to check
 * @param numTellers # of tellers
 * @return Pointer to customer event
 */
CustomerEvent *TellerEvent::checkOtherQueues(TellerQueue** queues,
		int numTellers) {

	//Find a queue with customers
	TellerQueue *line = nullptr;
	int largestQueue = 0;
	for (int i = 0; i < numTellers; i++) {

		TellerQueue *tempLine = queues[i];
		if (tempLine != queue) {
			if ((tempLine->getQueueSize() > largestQueue)) {
				line = tempLine;
				largestQueue = line->getQueueSize();
			}
		}
	}
	//If there are none
	if (line == nullptr) {
		return nullptr;

	}
	//Remove customer from that queue and then send it the open queue
	else {
		CustomerEvent *event = line->getHead()->getCustomerEvent();
		line->removeCustomer();
		return event;
	}
}
TellerEvent::~TellerEvent() {
	// TODO Auto-generated destructor stub
}


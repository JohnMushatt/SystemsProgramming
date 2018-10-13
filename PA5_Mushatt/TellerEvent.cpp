/*
 * TellerEvent.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "TellerEvent.h"
#include "EventQueue.h"
#include <iostream>
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
float TellerEvent::getTime() {
	return time;
}
int TellerEvent::getTotalIdles() {
	return totalIdles;
}
int TellerEvent::getTotalServices() {
	return totalServices;
}
float TellerEvent::getIdleTime() {
	return idleTime;
}
float TellerEvent::getServiceTime() {
	return tellerServiceTime;
}
void TellerEvent::action(float currentTime, TellerQueue** queues,
		int numTellers, EventQueue *simulationQueue) {

	simulationQueue->removeEvent();
	if (queue->getQueueSize() > 0) {

		CustomerEvent *cust = queue->getHead()->getCustomerEvent();

		cust->setTime(currentTime + this->getServiceTime());

		cust->setService();
		//std::cout<<"Customer has received service!\n";

		queue->removeCustomer();

		time = currentTime + tellerServiceTime;

		totalServices++;

		simulationQueue->addEvent(this);
		simulationQueue->addEvent(cust);
	} else {
		CustomerEvent *cust = checkOtherQueues(queues, numTellers);
		if (cust == nullptr) {
			time += this->idleTime;
			totalIdles++;
			simulationQueue->addEvent(this);

		} else {
			cust->setTime(currentTime + tellerServiceTime);
			cust->setService();
			//std::cout<<"Customer has received service!\n";
			time = currentTime + tellerServiceTime;
			totalServices++;

			simulationQueue->addEvent(this);
			simulationQueue->addEvent(cust);
		};
	}
}
CustomerEvent *TellerEvent::checkOtherQueues(TellerQueue** queues,
		int numTellers) {

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
	if (line == nullptr) {
		return nullptr;

	} else {
		CustomerEvent *event = line->getHead()->getCustomerEvent();
		line->removeCustomer();
		return event;
	}
}
TellerEvent::~TellerEvent() {
	// TODO Auto-generated destructor stub
}


/*
 * TellerQueue.cpp
 *
 *  Created on: Oct 6, 2018
 *      Author: jemushatt
 */

#include "TellerQueue.h"

TellerQueue::TellerQueue() {
	nextCustomer = nullptr;
	lastCustomer = nullptr;
	size = 0;
}
/**
 * Remove and return the next customer
 * @return Pointer to next customer
 */
Customer *TellerQueue::processCustomer() {

	//if queue is more than 0
	if (size > 0) {
		//If only 1 person queue
		if (size - 1 == 0) {
			lastCustomer = nullptr;

		}
		//Set temp to nextcustomer
		Customer *customer = nextCustomer;
		//Set head to the next in queue
		nextCustomer = nextCustomer->nextCustomer;
		//Reduce size of queue
		size--;

		return customer;
	}
	//If empty queue return nullptr
	return nullptr;
}
/**
 * Add customer to queue
 * @param *customer Pointer to customer
 * @return True if added, false if not
 */
bool TellerQueue::addCustomer(Customer *customer) {
	if(size==0) {
		nextCustomer = customer;
		lastCustomer = customer;
		size++;
		return true;
	}
	else if(size > 0) {
		lastCustomer->nextCustomer = customer;
		lastCustomer= customer;
		size++;
		return true;
	}
	return false;
}
TellerQueue::~TellerQueue() {
	// TODO Auto-generated destructor stub
}


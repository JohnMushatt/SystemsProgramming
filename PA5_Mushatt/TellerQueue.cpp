/*
 * TellerQueue.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "TellerQueue.h"
#include "Customer.h"
#include <iostream>
TellerQueue::TellerQueue() {
	nextCustomer = nullptr;
	lastCustomer = nullptr;
	size = 0;
}

/**
 * Returns customer at the beginning of the line
 * @return Pointer to 1st in line customer
 */
Customer *TellerQueue::getNextCustomer() {
	if (size > 0) {
		return nextCustomer;
	}
	return nullptr;
}
/**
 * Remove and return the next customer
 * @return Pointer to next customer
 */
Customer *TellerQueue::processCustomer(int processingTime) {
	std::cout<<"\nProcessing Customer"<<std::endl;
	//if queue is more than 0
	if (size > 0) {
		int currentTime = time(NULL);
		int elapsedTime = 0;
		while (elapsedTime < (processingTime)) {
			elapsedTime =time(NULL) - currentTime;
		}
		//If only 1 person queue
		if (size - 1 == 0) {
			nextCustomer = nullptr;
			lastCustomer = nullptr;

		}
		//Set temp to next customer
		Customer *customer = nextCustomer;
		//Set head to the next in queue
		if (customer != nullptr) {
			nextCustomer = nextCustomer->nextCustomer;
			//Reduce size of queue
			size--;
			std::cout<<"Customer Processed\n"<<std::endl;
			return customer;
		}
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
	//If queue is empty set next and last to customer and increase size
	if (size == 0) {
		nextCustomer = customer;
		lastCustomer = customer;
		size++;
		return true;
	}
	//If we have a non-empty queue update last customer and size
	else if (size > 0) {
		lastCustomer->setNextCustomer(customer);
		lastCustomer = customer;

		size++;
		return true;
	}
	return false;
}
/**
 * Returns the last customer in the queue
 * @return Pointer to last customer
 */
Customer *TellerQueue::getLastCustomer() {
	if (size > 0) {
		return lastCustomer;
	}
	return nullptr;
}
/**
 * Prints out teller queue
 */
void TellerQueue::printQueue() {
	int i = 0;
	Customer *cust = nextCustomer;
	std::cout << "Teller line size: " << size << std::endl;
	while (i < size) {
		std::cout << "Customer at position: " << i << " Time arrived: "
				<< cust->getTime() << std::endl;
		cust = cust->nextCustomer;
		i++;
	}
}
TellerQueue::~TellerQueue() {
	// TODO Auto-generated destructor stub
}


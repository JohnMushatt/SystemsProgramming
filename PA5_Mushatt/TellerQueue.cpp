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
	head = nullptr;
	tail = nullptr;
	size = 0;
}

/**
 * Returns customer at the beginning of the line
 * @return Pointer to 1st in line customer
 */
Customer *TellerQueue::getNextCustomer() {
	if (size > 0) {
		return head;
	}
	return nullptr;
}
/**
 * Remove and return the next customer
 * @return Pointer to next customer
 */
Customer *TellerQueue::processCustomer() {
	std::cout << "\nProcessing Customer" << std::endl;
	//if queue is more than 0
	if (size > 0) {
		//If only 1 person queue
		if (size - 1 == 0) {
			head = nullptr;
			tail = nullptr;

		}
		//Set temp to next customer
		Customer *customer = head;
		//Set head to the next in queue
		if (customer != nullptr) {
			head = head->nextCustomer;
			//Reduce size of queue
			size--;
			std::cout << "Customer Processed\n" << std::endl;
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
		head = customer;
		tail = customer;
		size++;
		return true;
	}
	//If we have a non-empty queue update last customer and size
	else if (size > 0) {
		tail->setNextCustomer(customer);
		tail = customer;

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
		return tail;
	}
	return nullptr;
}
/**
 * Prints out teller queue
 */
void TellerQueue::printQueue() {
	int i = 0;
	Customer *cust = head;
	std::cout << "Teller line size: " << size << std::endl;
	while (i < size) {
		std::cout << "Customer position: " << i << " Time arrived: "
				<< cust->getTime() << std::endl;
		cust = cust->nextCustomer;
		i++;
	}
}
/**
 * Returns size of teller queue
 * @return Size of queue
 */
int TellerQueue::getQueueSize() {
	return size;
}
TellerQueue::~TellerQueue() {
}


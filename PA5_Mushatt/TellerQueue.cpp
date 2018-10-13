/*
 * TellerQueue.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "TellerQueue.h"
#include <iostream>

#include "Customer.h"
TellerQueue::TellerQueue() {
	head = nullptr;
	size = 0;
}

/**
 * Returns customer at the beginning of the line
 * @return Pointer to 1st in line customer
 */
Customer *TellerQueue::getHead() {
	return head;
}
/**
 * Remove and return the next customer
 * @return Pointer to next customer
 */
void TellerQueue::removeCustomer() {
	if (size <= 1) {
		head = nullptr;
		size--;
	} else {
		Customer *cust = head;
		head = cust->getNextCustomer();
		size--;
	}
	/*
	 //Set temp to next customer
	 Customer *customer = head;

	 //If only 1 person queue
	 if (size == 1) {
	 head = nullptrptr;
	 tail = nullptrptr;
	 size--;
	 //teller->processing=true;

	 }
	 //Set head to the next in queue
	 else {
	 head = head->nextCustomer;
	 //Reduce size of queue
	 size--;
	 //teller->processing=true;
	 }
	 //If empty queue return nullptrptr

	 */
}

/**
 * Add customer to queue
 * @param *customer Pointer to customer
 * @return True if added, false if not
 */
void TellerQueue::addCustomer(Customer *customer) {

	if (size == 0) {
		head = customer;
		size++;
	} else {
		Customer *cust = head;
		for (int i = 1; i < size; i++) {
			cust = cust->nextCustomer;

		}
		cust->setNextCustomer(customer);
		size++;
	}
	/*
	 //If queue is empty set next and last to customer and increase size
	 if (size == 0) {
	 head = customer;
	 tail=customer;
	 size++;
	 return true;
	 }
	 //If we have a non-empty queue update last customer and size
	 else {
	 tail->nextCustomer=customer;
	 tail = customer;

	 size++;
	 return true;
	 }
	 return false;
	 */
}
/**
 * Returns the last customer in the queue
 * @return Pointer to last customer
 */

/**
 * Returns size of teller queue
 * @return Size of queue
 */
int TellerQueue::getQueueSize() {
	return size;
}
TellerQueue::~TellerQueue() {
}


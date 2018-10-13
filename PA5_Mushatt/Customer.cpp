/*
 * Customer.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "Customer.h"

Customer::Customer(CustomerEvent *event) {
	this->event=event;
	nextCustomer=nullptr;

}

/**
 * Set nextCustomer to cust
 * @param cust Pointer to new customer
 */
void Customer::setNextCustomer(Customer *cust) {
	nextCustomer = cust;
}
/**
 * Retrieve the nextCustomer
 * @return Pointer to the next customer
 */
Customer *Customer::getNextCustomer() {
	return nextCustomer;
}
/**
 * Retrieves the customer's event
 * @return Pointer to event
 */
CustomerEvent *Customer::getCustomerEvent() {
	return event;
}
Customer::~Customer() {
	// TODO Auto-generated destructor stub
}

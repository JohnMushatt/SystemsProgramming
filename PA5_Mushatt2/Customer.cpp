/*
 * Customer.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "Customer.h"

Customer::Customer(CustomerEvent *event) {
	this->event=event;
	nextCustomer=NULL;

}
void Customer::setNextCustomer(Customer *cust) {
	nextCustomer = cust;
}
Customer::~Customer() {
	// TODO Auto-generated destructor stub
}

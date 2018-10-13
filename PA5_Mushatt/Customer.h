/*
 * Customer.h
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include "CustomerEvent.h"
class Customer{
public:
	Customer();
	virtual ~Customer();
	Customer(CustomerEvent *event);
	void setNextCustomer(Customer *cust);
	Customer *nextCustomer;
	CustomerEvent *event;
	Customer *getNextCustomer();
	CustomerEvent *getCustomerEvent();
};

#endif /* CUSTOMER_H_ */

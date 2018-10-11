/*
 * TellerQueue.h
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#ifndef TELLERQUEUE_H_
#define TELLERQUEUE_H_
#include "Customer.h"
#include "Teller.h"
class Customer;
class Teller;
class TellerQueue {
public:
	TellerQueue();
	virtual ~TellerQueue();
	Customer *processCustomer();
	bool addCustomer(Customer *customer);
	Customer *getLastCustomer();
	void printQueue();
	Customer *getNextCustomer();
	int getQueueSize();
	Teller *teller;
private:
	Customer *head;
	Customer *tail;
	int size;
};

#endif /* TELLERQUEUE_H_ */

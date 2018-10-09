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
class TellerQueue {
public:
	TellerQueue();
	virtual ~TellerQueue();
	Customer *processCustomer();
	bool addCustomer(Customer *customer);
	Customer *getLastCustomer();
	void printQueue();
private:
	Customer *nextCustomer;
	Customer *lastCustomer;
	int size;
};

#endif /* TELLERQUEUE_H_ */

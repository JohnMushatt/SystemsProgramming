/*
 * TellerQueue.h
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#ifndef TELLERQUEUE_H_
#define TELLERQUEUE_H_
#include "Teller.h"
#include <vector>

#include "Customer.h"
class TellerQueue {
public:
	TellerQueue();
	virtual ~TellerQueue();
	void addCustomer(Customer *customer);
	Customer *getHead();
	int getQueueSize();
	void removeCustomer();
private:
	Customer *head;
	int size;
};

#endif /* TELLERQUEUE_H_ */

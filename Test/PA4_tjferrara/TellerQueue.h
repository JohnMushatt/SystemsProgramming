/*
 * TellerQueue.h
 *
 *  Created on: Feb 14, 2018
 *      Author: tjferrara
 */

#include "TellerQueueNode.h"

#ifndef TELLERQUEUE_TELLERQUEUE_H_
#define TELLERQUEUE_TELLERQUEUE_H_

class TellerQueue {
public:
	TellerQueue();
	virtual ~TellerQueue();
	int getSize();
	TellerQueueNode* top();
	void pop();
	void push(TellerQueueNode* node);
private:
	int size;
	TellerQueueNode* head;
};

#endif /* TELLERQUEUE_TELLERQUEUE_H_ */

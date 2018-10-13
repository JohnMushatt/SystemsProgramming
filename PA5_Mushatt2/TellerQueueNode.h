/*
 * TellerQueueNode.h
 *
 *  Created on: Feb 14, 2018
 *      Author: tjferrara
 */

#include "CustomerEvent.h"

#ifndef TELLERQUEUE_TELLERQUEUENODE_H_
#define TELLERQUEUE_TELLERQUEUENODE_H_

class TellerQueueNode {
public:
	TellerQueueNode(CustomerEvent* customer);
	virtual ~TellerQueueNode();
	CustomerEvent* getVal();
	TellerQueueNode* getPrev();
	void setPrev(TellerQueueNode* node);
private:
	CustomerEvent* val;
	TellerQueueNode* prev;
};

#endif /* TELLERQUEUE_TELLERQUEUENODE_H_ */

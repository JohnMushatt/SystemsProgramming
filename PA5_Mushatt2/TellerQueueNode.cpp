/*
 * TellerQueueNode.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: tjferrara
 */

#include "TellerQueueNode.h"
#include "stdlib.h"

/**Constructs TellerQueueNode to be inserted into TellerQueue
 * @param customer to be set to value of node
 */
TellerQueueNode::TellerQueueNode(CustomerEvent* customer) {
	val = customer;
	prev = NULL;
}

/**Destructor of TellerQueueNode
 */
TellerQueueNode::~TellerQueueNode() {
}

/** Retrieves the value of TellerQueueNode
 * @return CustomerEvent pointer
 */
CustomerEvent* TellerQueueNode::getVal() {
	return val;
}

/** Retrieves the previous node of TellerQueueNode
 * @return pointer to previous node in LinkedList
 */
TellerQueueNode* TellerQueueNode::getPrev() {
	return prev;
}

/**Sets the Previous value to given node
 * @param node TellerQueueNode to point to for previous node
 */
void TellerQueueNode::setPrev(TellerQueueNode* node) {
	prev = node;
}

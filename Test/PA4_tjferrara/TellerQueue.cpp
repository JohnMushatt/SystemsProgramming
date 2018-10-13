/*
 * TellerQueue.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: tjferrara
 */

#include "TellerQueue.h"
#include "stdlib.h"

/**Constructs TellerQueue
 */
TellerQueue::TellerQueue() {
	size = 0;
	head = NULL;
}

/**Destructs TellerQueue
 */
TellerQueue::~TellerQueue() {

}

/**Gets size of current TellerQueue
 * @return size of Queue
 */
int TellerQueue::getSize() {
	return size;
}

/**Gets head of current TellerQueue
 * @return head of Queue
 */
TellerQueueNode* TellerQueue::top() {
	return head;
}

/**Removes head of current TellerQueue
 */
void TellerQueue::pop() {
	if (size <= 1) { 	// Remove last Element
		head = NULL;
		size--;
	} else {			// Chop off head
		TellerQueueNode* oldHead = head;
		head = oldHead->getPrev();
		size--;
	}
}

/**Adds TellerQueueNode to TellerQueue based
 * @param node Event to pass into EventQueue
 */
void TellerQueue::push(TellerQueueNode* node) {
	if (size == 0) {	// First Element Being added
		head = node;
		size++;
	} else {			// New Element attach to tail
		TellerQueueNode* tail = head;
		for (int i = 1; i < size; i++) {
			tail = tail->getPrev();
		}
		tail->setPrev(node);
		size++;
	}
}

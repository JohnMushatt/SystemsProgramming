/*
 * EventQueue.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: tjferrara
 */

#include "EventQueue.h"
#include <iostream>
#include "stdlib.h"

/**Constructs EventQueue
 */
EventQueue::EventQueue() {
	size = 0;
	head = NULL;
}

/**Destructs EventQueue
 */
EventQueue::~EventQueue() {

}

/**Gets size of current EventQueue
 * @return size of Queue
 */
int EventQueue::getSize() {
	return size;
}

/**Gets head of current EventQueue
 * @return head of Queue
 */
Event* EventQueue::top() {
	return head;
}

/**Removes head of current EventQueue
 */
void EventQueue::pop() {
	if (size <= 1) { 	// Remove last Element
		delete head;
		head = NULL;
		size--;
	} else {			// Chop off head
		Event* oldHead = head;
		head = oldHead->getPrev();
		size--;
	}
}

/**Gets Event at a specific depth in EventQueue
 * @param index index to get in EventQueue
 * @return Event at index
 */
Event* EventQueue::getAt(int index) {
	if (size > index) {
		Event* next = head;
		for (int i = 0; i < index; i++) {
			next = next->getPrev();
		}
		return next;
	} else {
		std::cerr
				<< "ERROR: Attempted to access index out of bounds of EventQueue!\n";
		return NULL;
	}
}

/**Adds Event to EventQueue based on time value
 * @param node Event to pass into EventQueue
 */
void EventQueue::push(Event* node) {
	if (size < 1) {	// Add to Top
		head = node;
		size++;
	} else { 			// Add to Body
		bool addedNode = false;
		Event* next = head;
		for (int i = 0; i < size; i++) {
			if (node->getTime() < next->getTime()) {
				node->setPrev(next);
				if (next == head) { // Check if replacing head
					head = node;
				} else {			// Attach previous element to node
					getAt(i - 1)->setPrev(node);
				}
				addedNode = true;
				break;
			} else {				// Move down to next element
				next = next->getPrev();
			}
		}
		if (!addedNode) {			// Add node to end of elements
			getAt(size - 1)->setPrev(node);
		}
		size++;
	}
}

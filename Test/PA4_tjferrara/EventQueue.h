/*
 * EventQueue.h
 *
 *  Created on: Feb 14, 2018
 *      Author: tjferrara
 */

#include "Event.h"

#ifndef EVENTQUEUE_EVENTQUEUE_H_
#define EVENTQUEUE_EVENTQUEUE_H_

class EventQueue {
public:
	EventQueue();
	virtual ~EventQueue();
	int getSize();
	Event* top();
	void pop();
	void push(Event* node);
private:
	Event* getAt(int index);
	int size;
	Event* head;
};

#endif /* EVENTQUEUE_EVENTQUEUE_H_ */

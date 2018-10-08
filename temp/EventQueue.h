/*
 * EventQueue.h
 *
 *  Created on: Oct 6, 2018
 *      Author: jemushatt
 */

#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_
#include "Event.h"
class EventQueue {
public:
	EventQueue();
	virtual ~EventQueue();
	Event *getHead();
	Event *getTail();
	Event *removeEvent();
	bool addEvent(Event *event);
	int getQueueSize();
private:
	Event *head;
	Event *tail;
	int size;

};

#endif /* EVENTQUEUE_H_ */

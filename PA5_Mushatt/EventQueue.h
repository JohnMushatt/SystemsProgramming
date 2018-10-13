/*
 * EventQueue.h
 *
 *  Created on: Oct 8, 2018
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
	void removeEvent();
	void addEvent(Event *event);
	int getQueueSize();
	Event *getEventAt(int index);

private:
	Event *head;
	int size;

};

#endif /* EVENTQUEUE_H_ */

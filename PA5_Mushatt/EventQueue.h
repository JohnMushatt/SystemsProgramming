/*
 * EventQueue.h
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_
#include "Event.h"
#include <vector>
class EventQueue {
public:
	EventQueue(int nTellers);
	virtual ~EventQueue();
	Event *getHead();
	Event *getTail();
	Event *removeEvent();
	void addEvent(Event *event);
	int getQueueSize();
	std::vector<TellerQueue *> tellers;
	int lastQueueUsed;

private:
	Event *head;
	Event *tail;
	int size;

};

#endif /* EVENTQUEUE_H_ */

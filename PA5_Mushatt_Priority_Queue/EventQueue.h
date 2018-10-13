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
#include <queue>
/**
 * Priority Queue implementation of EventQueue
 */
class CompareEventTime {
public:
	/**
	 * Overriding the operator for the priority queue to return true if e1 is greater than e2
	 */
	bool operator()(Event *e1, Event *e2){
			if(e1->getTime()>e2->getTime()) {
				return true;
			}
			else return false;
		}
};
class EventQueue {
public:
	EventQueue();
	virtual ~EventQueue();
	Event *getHead();
	void removeEvent();
	void addEvent(Event *event);
	int getQueueSize();
	Event *getEventAt(int index);
	//Priority queue of type Event* constructed with a vector of type Event* using the comparrison CompareEventTyime class
	std::priority_queue<Event *,std::vector<Event *>,CompareEventTime> pQueue;
private:

};

#endif /* EVENTQUEUE_H_ */

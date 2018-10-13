/*
 * Event.h
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#ifndef EVENT_H_
#define EVENT_H_
#include <vector>

class EventQueue;
class TellerQueue;

class Event {
public:
	Event();
	virtual ~Event();
	virtual float getTime();
	virtual void action(float currentTime, TellerQueue** queues,int numTellers, EventQueue *simulationQueue);
	Event *getNextEvent();
	void setNext(Event *event);
private:
	float time;
	Event *nextEvent;

};
#endif /* EVENT_H_ */

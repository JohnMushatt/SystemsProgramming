/*
 * Event.h
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#ifndef EVENT_H_
#define EVENT_H_
#include "Actor.h"
#include "TellerQueue.h"
#include <iostream>
class Actor;
class Event {
public:
	Event(int time);
	virtual ~Event();
	Event *nextEvent;
	int getEventTime();
	Event virtual *action(TellerQueue *line) = 0;
	bool isTellerEvent;
	int time;

private:
};

#endif /* EVENT_H_ */

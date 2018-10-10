/*
 * Event.h
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#ifndef EVENT_H_
#define EVENT_H_

class Event {
public:
	Event(int time);
	virtual ~Event();
	Event *nextEvent;
	int getEventTime();

private:
	int time;
};

#endif /* EVENT_H_ */

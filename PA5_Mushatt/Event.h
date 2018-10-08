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
	Event();
	virtual ~Event();
	Event *nextEvent;
};

#endif /* EVENT_H_ */

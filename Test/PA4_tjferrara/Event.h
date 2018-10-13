/*
 * Event.h
 *
 *  Created on: Feb 14, 2018
 *      Author: tjferrara
 */


#ifndef EVENT_H_
#define EVENT_H_

class TellerQueue;
class EventQueue;

class Event {
public:
	Event();
	virtual ~Event();
	virtual void action(float clock, TellerQueue** lines, int numLines, EventQueue* eventQueue);
	virtual float getTime();
	Event* getPrev();
	void setPrev(Event* event);
private:
	float time;
	Event* prev;
};

#endif /* EVENT_H_ */

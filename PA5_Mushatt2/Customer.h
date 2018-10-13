/*
 * CustomerEvent.h
 *
 *  Created on: Feb 14, 2018
 *      Author: tjferrara
 */

#include "Event.h"

#ifndef CUSTOMEREVENT_H_
#define CUSTOMEREVENT_H_

class CustomerEvent : public Event {
public:
	CustomerEvent(float aTime);
	virtual ~CustomerEvent();
	void action(float clock, TellerQueue** lines, int numLines, EventQueue* eventQueue);
	void setTime(float t);
	void setServicing();
	bool getServicing();
	float getTime();
	float getLeaveTime();
	float getArrivalTime();
private:
	TellerQueue* findShortestLine(TellerQueue** lines, int numLines);
	float arrivalTime;
	float time;
	float leaveTime;
	bool servicing;
};

#endif /* CUSTOMEREVENT_H_ */

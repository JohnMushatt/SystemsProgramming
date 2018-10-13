/*
 * TellerEvent.h
 *
 *  Created on: Feb 14, 2018
 *      Author: tjferrara
 */

#include "Event.h"
#include "TellerQueue.h"

#ifndef TELLEREVENT_H_
#define TELLEREVENT_H_

class TellerEvent : public Event {
public:
	TellerEvent(float sTime, float iTime, TellerQueue* line);
	virtual ~TellerEvent();
	void action(float clock, TellerQueue** lines, int numLines, EventQueue* eventQueue);
	float getServiceTime();
	float getTime();
	void setTime(float t);
	int getNumServices();
	float getIdleTime();
	int getNumIdles();
private:
	CustomerEvent* getCustomerFromLargestLine(TellerQueue** lines, int numLines);
	TellerQueue* queue;
	float time;
	float serviceTime;
	float idleTime;
	int numServices;
	int numIdles;
};

#endif /* TELLEREVENT_H_ */
